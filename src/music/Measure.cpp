#include "Measure.h"

Measure::Measure(TimeSignature time_signature)
    : time_signature_(time_signature) {
    beats_ = std::vector<Beat>(time_signature_.beats_per_measure);
}

Beat* Measure::GetBeat(int index) { return &beats_.at(index); }

void Measure::Clear() { beats_.clear(); }

void Measure::SetBPM(int bpm) {
    for (Beat beats : beats_) {
        beats.SetBPM(bpm);
    }
}