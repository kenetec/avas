#pragma once

#include "ofMain.h"
#include "Beat.h"
#include <vector>

struct TimeSignature {
    int beats_per_measure;
    NoteType note_type_as_beat;
};

class Measure {
   public:
    Measure(TimeSignature time_signature);
    Beat* GetBeat(int index);
    void Clear();
    void SetBPM(int bpm);
   private:
    TimeSignature time_signature_;
    std::vector<Beat> beats_;
};