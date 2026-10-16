#pragma once

#include <inttypes.h>

namespace drivers::encoder
{ 
    struct EncoderParam
    {
        uint8_t pin_clc_a;
        uint8_t pin_b;
        int8_t polarity; // 1 = normal, -1 = reversed
    };
    
};