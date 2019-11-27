#include "Score.h"

void Score::PushMeasure(Measure measure) { measures_.push_back(measure); }

void Score::RemoveMeasure(int index) {
    auto target_index = measures_.cbegin() + index;
    measures_.erase(target_index, target_index);
}

void Score::SetBPM(int bpm) {
    bpm_ = bpm;

    for (Measure measure : measures_) {
        measure.SetBPM(bpm);
    }
}