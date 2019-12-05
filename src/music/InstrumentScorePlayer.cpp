#include "InstrumentScorePlayer.h"

InstrumentScorePlayer::InstrumentScorePlayer() {}

void InstrumentScorePlayer::setup(InstrumentScore& score,
                                  double ms_between_beats) {
    instrument_score_ = score;
    ms_between_beats_ = ms_between_beats;
}

void InstrumentScorePlayer::threadedFunction() {
    Instrument* instrument = instrument_score_.instrument;
    std::vector<Measure> measures = instrument_score_.measures;

    if (instrument != nullptr) {
        for (int measure_index = 0; measure_index < measures.size();
             measure_index++) {
            Measure measure = measures.at(measure_index);
            measure_player_.setup(measure, instrument, ms_between_beats_);

            measure_player_.startThread();
            measure_player_.waitForThread();
        }
    }
}