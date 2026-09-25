#pragma once

#include <inttypes.h>

namespace drivers::motor
{
    struct MotorParams
    {
        uint8_t dir_pin;
        uint8_t pwm_pin;
        uint8_t polarity; // 0 - normal, 1 = reversed
        float(*get_voltage)();
    };

    class MotorDriver : public MotorParams {
    public:
        MotorDriver(MotorParams &params) : MotorParams(params) {};
        void init();
        void set_voltage(float u);
    };
    
};