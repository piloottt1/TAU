#include "drivers/driver_manager.hpp"
#include "servo/servo_controller.hpp"

#include <Arduino.h>

servo::ServoControllerParams left_servo_params = {
    .motor = drivers::motor_left,
    .encoder = drivers::encoder_left,
    .kp = 0.0f,
    .ki = 0.0f,
    .velocity_filter = 1.0f
};

servo::ServoController left_servo(left_servo_params);

void setup()
{
  drivers::init();
  left_servo.init();
  drivers::motor_left.set_voltage(3.0);
  Serial.begin(115200);
}

void loop()
{
  //drivers::motor_left.set_voltage(1);
  //drivers::motor_right.set_voltage(1);
  left_servo.update(0.0f);
  Serial.println(left_servo.get_velocity());
  delay(100); //14.19
}