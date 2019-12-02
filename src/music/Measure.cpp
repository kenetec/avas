#include "Measure.h"

Measure::Measure(TimeSignature time_signature) : time_signature(time_signature) {
    for (int beat_index = 0; beat_index < time_signature.beats_per_measure; beat_index++) {
        beats.push_back(Beat());
    }
 }