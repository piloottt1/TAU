#pragma once

#include <inttypes.h>

namespace drivers::motor
{
    struct MotorParams
    {
        uint8_t dir_pin;
        uint8_t pwm_pin;
    };

    class MotorDriver : public MotorParams {
    public:
        MotorDriver(MotorParams &params) : MotorParams(params) {};
        void init();
        void set_voltage(float u);
    };
    
};