#include "servo_controller.hpp"

#include "drivers/motor/motor.hpp"
#include "drivers/encoder/encoder.hpp"

#include <Arduino.h>

namespace servo
{   
    void ServoController::init()
    {
        encoder.tick();
        velocity_estimator_.init(encoder.phi_rad);
        velocity_ = 0.0f;
    }

    void ServoController::update(float target_velocity)
    {
        encoder.tick();
        velocity_estimator_.update(encoder.phi_rad);
        velocity_ = velocity_estimator_.get_velocity();
    }

    float ServoController::get_velocity() const
    {
        return velocity_;
    }
};
