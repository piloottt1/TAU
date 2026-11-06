#include "velocity_estimator.hpp"

#include <Arduino.h>

namespace servo
{
    void VelocityEstimator::init(float position)
    {
        velocity_ = 0.0f;
        previous_position_ = position;
        previous_time_ = micros();
    }

    void VelocityEstimator::update(float position)
    {
        uint32_t current_time = micros();
        uint32_t delta_time = current_time - previous_time_;

        if (delta_time == 0)
        {
            return;
        }

        float dt = delta_time * 1e-6f;

        float raw_velocity = (position - previous_position_) / dt;

        velocity_ += velocity_filter_ * (raw_velocity - velocity_);

        previous_position_ = position;
        previous_time_ = current_time;
    }

    float VelocityEstimator::get_velocity() const
    {
        return velocity_;
    }
}