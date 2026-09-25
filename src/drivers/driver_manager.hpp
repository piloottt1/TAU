#pragma once

#include "motor/motor.hpp"
#include "battery_volts/battery_volts.hpp"

namespace drivers
{

    extern motor::MotorDriver motor_left, motor_right;

    void init();

};
