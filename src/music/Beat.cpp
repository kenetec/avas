#include "Beat.h"

Beat::Beat() {
    for (int i = 0; i < kMaxOctaves; i++) {
        for (int j = 0; j < kNotesPerOctaves; j++) {
            notes_.push_back(Note(kNoteNames.at(j), i));
        }
    }
};

Beat& Beat::operator=(const Beat& beat) {
    notes_ = beat.notes_;
    return *this;
}