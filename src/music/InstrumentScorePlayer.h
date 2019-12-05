#pragma once

#include <ofMain.h>
#include "Score.h"
#include "MeasurePlayer.h"

class InstrumentScorePlayer : public ofThread {
   private:
    MeasurePlayer measure_player_;
    InstrumentScore instrument_score_;
    double ms_between_beats_ = 0;
   public:
    InstrumentScorePlayer();
    void setup(InstrumentScore& score, double ms_between_beats);
    void threadedFunction();
};
