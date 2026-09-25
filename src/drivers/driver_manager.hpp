#pragma once

#include "motor/motor.hpp"

namespace drivers
{

    extern motor::MotorDriver motor_left, motor_right;

    void init();

};
