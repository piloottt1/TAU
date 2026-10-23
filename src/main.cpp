#include "drivers/driver_manager.hpp"

#include <Arduino.h>

void setup()
{
  drivers::init();
  
  Serial.begin(115200);
}

void loop()
{
  //drivers::motor_left.set_voltage(1);
  //drivers::motor_right.set_voltage(1);
  drivers::encoder_left.tick();
  drivers::encoder_right.tick();
  Serial.println("left");
  Serial.println(drivers::encoder_left.phi_rad);
  Serial.println("right");
  Serial.println(drivers::encoder_right.phi_rad);
  delay(100);
}