#include "driver_manager.hpp"

#include <Arduino.h>

namespace drivers
{
    battery_volts::BatteryVoltsParams battery_volts_params = {
        .scale = 2.0,
        .pin = A7
    };

    battery_volts::BatteryVoltsDriver battery_volts_driver(battery_volts_params);

    float get_voltage()
    {
        return battery_volts_driver.get_volts();
    }

    motor::MotorParams motor_left_params = {
        .dir_pin = 7,
        .pwm_pin = 9,
        .polarity = 0,
        .get_voltage = get_voltage
    };
    
    motor::MotorParams motor_right_params = {
        .dir_pin = 8,
        .pwm_pin = 10,
        .polarity = 1,
        .get_voltage = get_voltage
    };

    motor::MotorDriver motor_left(motor_left_params);
    motor::MotorDriver motor_right(motor_right_params);

    encoder::EncoderParams encoder_left_params = {
        //.tick_to_rad = 1.0,
        .tick_to_rad = 4.0 * 10.0 * M_PI / 14280,
        .pin_clk_a = 2,
        .pin_b = 4,
        .polarity = -1
    };

    encoder::EncoderParams encoder_right_params = {
        //.tick_to_rad = 1.0,
        .tick_to_rad = 4.0 * 10.0 * M_PI / 14280,
        .pin_clk_a = 3,
        .pin_b = 5,
        .polarity = 1
    };

    encoder::EncoderDriver encoder_left(encoder_left_params);
    encoder::EncoderDriver encoder_right(encoder_right_params);

    void encoder_left_irq()
    {
        encoder_left.tick_irq();
    }
    
    void encoder_right_irq()
    {
        encoder_right.tick_irq();
    }

    void init()
    {
        battery_volts_driver.init();
        motor_left.init();
        motor_right.init();
        encoder_left.init();
        encoder_right.init();

        attachInterrupt(digitalPinToInterrupt(encoder_left_params.pin_clk_a), encoder_left_irq, CHANGE);
        attachInterrupt(digitalPinToInterrupt(encoder_right_params.pin_clk_a), encoder_right_irq, CHANGE);
    }
};