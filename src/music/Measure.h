#pragma once

#include <vector>
#include "Beat.h"

struct TimeSignature {
    int beats_per_measure;
    NoteType note_type_as_beat;
};

struct Measure {
    Measure() : Measure(TimeSignature{4, NoteType::QUARTER}){};
    Measure(TimeSignature time_signature);

    TimeSignature time_signature;
    std::vector<Beat> beats;
};
