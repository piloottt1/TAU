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
        digitalWrite(dir_pin, u > 0);

        int pwm = abs(u) / 9.0 * 255;

        analogWrite(pwm_pin, pwm);
    }
};