#include "Measure.h"

Measure::Measure(TimeSignature time_signature)
    : time_signature_(time_signature) {
    beats_ = std::vector<Beat>(time_signature_.beats_per_measure, Beat());
 }

Beat* Measure::GetBeat(int index) { return &beats_.at(index); }

void Measure::Clear() {
    for (Beat beat : beats_) {
		// change beats to rests
        beat.ToRest();
    }
}

void Measure::SetBPM(int bpm) {
    for (Beat beat : beats_) {
        beat.SetBPM(bpm);
    }
}