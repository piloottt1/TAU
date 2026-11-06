#include "encoder.hpp"

#include <Arduino.h>

namespace drivers::encoder
{

int8_t fsm_table[4][4] {
    {0, -1, -1, 0},
    {-1, 0, 0, 1},
    {1, 0, 0, -1},
    {0, -1, 1, 0}
};

void EncoderDriver::init()
{
    pinMode(pin_clk_a, INPUT);
    pinMode(pin_b, INPUT);
    int8_t clk_a = digitalRead(pin_clk_a);
    int8_t b = digitalRead(pin_b);
    int8_t a = clk_a ^ b;
    ab_prev = (a << 1) | b;
    ticks = 0;
    phi_rad_ = 0.0f;
}

void EncoderDriver::tick_irq()
{
    int8_t clk_a = digitalRead(pin_clk_a);
    int8_t b = digitalRead(pin_b);
    int8_t a = clk_a ^ b;
    int8_t ab = (a << 1) | b;
    ticks += fsm_table[ab_prev][ab] * polarity;
    ab_prev = ab;
}

void EncoderDriver::tick()
{
    noInterrupts();
    int32_t ticks_tmp = ticks;
    ticks = 0;
    interrupts();
    phi_rad_ += ticks_tmp * tick_to_rad;
}

void EncoderDriver::reset() {
    noInterrupts();
    ticks = 0;
    interrupts();
    phi_rad_ = 0.0f;
}

};