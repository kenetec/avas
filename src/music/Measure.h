#pragma once

#include <vector>
#include "Beat.h"

struct TimeSignature {
    int beats_per_measure;
    NoteType note_type_as_beat;
};

class Measure {
   public:
    Measure() : Measure(TimeSignature{4, NoteType::QUARTER}){};
    Measure(TimeSignature time_signature);
    ~Measure();

    void SetTimeSignature(TimeSignature time_signature);
    Beat& GetBeat(int index);
    void Clear();
    void SetBPM(int bpm);
    TimeSignature GetTimeSignature() { return time_signature_; };

   private:
    TimeSignature time_signature_;
    std::vector<Beat> beats_;
};
