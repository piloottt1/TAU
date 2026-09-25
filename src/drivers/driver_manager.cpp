#include "driver_manager.hpp"

#include <Arduino.h>

namespace drivers
{
    battery_volts::BatteryVoltsParams battery_volts_params = {
        .scale = 2.0,
        .pin = A7};

    battery_volts::BatteryVoltsDriver battery_volts_driver(battery_volts_params);

    float get_voltage()
    {
        return battery_volts_driver.get_volts();
    }

    motor::MotorParams motor_left_params = {
        .dir_pin = 7,
        .pwm_pin = 9,
        .polarity = 0,
        .get_voltage = get_voltage};
    
    motor::MotorParams motor_right_params = {
        .dir_pin = 8,
        .pwm_pin = 10,
        .polarity = 1,
        .get_voltage = get_voltage};

    motor::MotorDriver motor_left(motor_left_params);
    motor::MotorDriver motor_right(motor_right_params);

    void init()
    {
        motor_left.init();
        motor_right.init();

        battery_volts_driver.init();
    }
};