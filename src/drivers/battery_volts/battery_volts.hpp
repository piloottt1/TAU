#pragma once

#include <inttypes.h>

namespace drivers::battery_volts
{
    struct BatteryVoltsParams
    {
        float scale;
        uint8_t pin; 
    };
    
    class BatteryVoltsDriver : public BatteryVoltsParams
    {
    public:
        BatteryVoltsDriver(BatteryVoltsParams &params) : BatteryVoltsParams(params) {};
        void init();
        float get_volts(); 
    };
}