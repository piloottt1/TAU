#pragma once

#include <inttypes.h>

namespace drivers::encoder
{ 
    struct EncoderParams
    {
        float tick_to_rad;
        uint8_t pin_clk_a;
        uint8_t pin_b;
        int8_t polarity; // 1 = normal, -1 = reversed
    };

    class EncoderDriver : private EncoderParams
    {
    public:
        const float &phi_rad;
        EncoderDriver(EncoderParams &params) : EncoderParams(params), phi_rad(phi_rad_) {};
        void init();
        void tick();
        void tick_irq();
        void reset();
    private:
        int8_t ab_prev;
        volatile int32_t ticks;
        float phi_rad_;
    };
};