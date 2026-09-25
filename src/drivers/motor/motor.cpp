#include "motor.hpp"

#include <Arduino.h>

namespace drivers::motor
{
    void init()
    {
        pinMode(9, OUTPUT);
        pinMode(10, OUTPUT);
    }

    void set_voltage(float voltage)
    {
        analogWrite(9, voltage);
        analogWrite(10, voltage);
    }

}; // namespace drivers::motor