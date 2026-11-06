#pragma once

#include <inttypes.h>

namespace servo
{
    class VelocityEstimator
    {
    public:
        VelocityEstimator(float velocity_filter) : velocity_filter_(velocity_filter) {};
        void init(float position);
        void update(float position);
        float get_velocity() const;
    private:
        float velocity_;
        float previous_position_;
        uint32_t previous_time_;
        float velocity_filter_;
    };
}