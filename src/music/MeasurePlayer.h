#pragma once

#include <ofMain.h>
#include "Measure.h"
#include "Instrument.h"

class MeasurePlayer : public ofThread {
   private:
    Measure measure_;
    double sleep_time_ms_;
    Instrument* instrument_;

   public:
    MeasurePlayer();

	void setup(Measure& measure, Instrument* instrument, double sleep_time_ms);
    void threadedFunction();
};
