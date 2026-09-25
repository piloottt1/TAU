#include <Arduino.h>

#include "drivers/motor/motor.hpp"
#include "drivers/encoder/encoder.hpp"

void setup()
{
  drivers::motor::init();
  drivers::encoder::init();

  drivers::motor::set_voltage(0.5);
}

void loop()
{
  float angle = drivers::encoder::get_angle();
  Serial.println(angle);
}