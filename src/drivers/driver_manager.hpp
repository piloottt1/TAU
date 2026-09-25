#pragma once

#include "motor/motor.hpp"
#include "battery_volts/battery_volts.hpp"

namespace drivers
{
    extern battery_volts::BatteryVoltsDriver battery_volts_driver;
    extern motor::MotorDriver motor_left, motor_right;

    void init();

};
