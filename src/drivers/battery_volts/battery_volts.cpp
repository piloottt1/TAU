#include "battery_volts.hpp"

#include <Arduino.h>

namespace drivers::battery_volts
{
    void BatteryVoltsDriver::init()
    {
        pinMode(pin, INPUT);
    }

    float BatteryVoltsDriver::get_volts()
    {
        return (float)analogRead(pin) / 1024.0 * 5.0 * scale;
    }
}