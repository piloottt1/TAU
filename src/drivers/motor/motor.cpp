#include "motor.hpp"

#include <Arduino.h>

namespace drivers::motor
{   
    void MotorDriver::init()
    {
        pinMode(dir_pin, OUTPUT);
        pinMode(pwm_pin, OUTPUT);
    }

    void MotorDriver::set_voltage(float u)
    {
        digitalWrite(dir_pin, (u > 0) ^ polarity);

        uint8_t pwm = constrain(abs(u) / get_voltage() * 255, 0, 255);

        analogWrite(pwm_pin, pwm);
    }
};