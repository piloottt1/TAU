#include "driver_manager.hpp"

namespace drivers
{
    motor::MotorParams motor_left_params = {
        .dir_pin = 7,
        .pwm_pin = 9};
    
    motor::MotorParams motor_right_params = {
        .dir_pin = 8,
        .pwm_pin = 10};

    motor::MotorDriver motor_left(motor_left_params);
    motor::MotorDriver motor_right(motor_right_params);

    void init()
    {
        motor_left.init();
        motor_right.init();
    }
};