#include "drivers/driver_manager.hpp"

#include <Arduino.h>

void setup()
{
  drivers::init();

  Serial.begin(115200);
}

void loop()
{
  drivers::motor_left.set_voltage(1);
  drivers::motor_right.set_voltage(1);

  //Serial.println(drivers::battery_volts_driver.get_volts());
  //delay(1000);
}