#include "Measure.h"

Measure::Measure(TimeSignature time_signature)
    : time_signature_(time_signature) {
    for (int beat_index = 0;
         beat_index < time_signature_.beats_per_measure;
         beat_index++) {
        //beats_.push_back(new Beat());
        beats_.push_back(Beat());
    }
 }

Measure::~Measure() {
     for (int beat_index = 0; beat_index < time_signature_.beats_per_measure;
          beat_index++) {
         //delete beats_.at(beat_index);
     }
 }

void Measure::SetTimeSignature(TimeSignature time_signature) {
     time_signature_ = time_signature;
 }

Beat& Measure::GetBeat(int index) { return beats_.at(index); }

void Measure::Clear() {
    for (Beat& beat : beats_) {
		// change beats to rests
        beat.ToRest();
    }
}

void Measure::SetBPM(int bpm) {
    for (Beat& beat : beats_) {
        beat.SetBPM(bpm);
    }
}