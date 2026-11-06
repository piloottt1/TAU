#pragma once

#include "pi_regulator.hpp"
#include "velocity_estimator.hpp"
#include <inttypes.h>

namespace drivers::motor
{
    class MotorDriver;
}

namespace drivers::encoder
{
    class EncoderDriver;
}

namespace servo
{
    struct ServoControllerParams
    {
        drivers::motor::MotorDriver& motor;
        drivers::encoder::EncoderDriver& encoder;
        float kp;
        float ki;
        float velocity_filter;
    };

    class ServoController : private ServoControllerParams
    {
    public:
        ServoController(const ServoControllerParams& params) : ServoControllerParams(params), velocity_estimator_(params.velocity_filter) {};
        void init();
        void update(float target_velocity);
        float get_velocity() const;
    private:
        VelocityEstimator velocity_estimator_;
        //PIRegulator regulator_;

        float velocity_;
    };
}