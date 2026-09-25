#include "encoder.hpp"

#include <Arduino.h>

namespace drivers::encoder
{
    void init()
    {
        pinMode(2, INPUT);
        pinMode(3, INPUT);
    }

    float get_angle()
    {
        return (float)analogRead(2) - (float)analogRead(3);
    }
}; // namespace drivers::encoder