#include "Beat.h"

Beat::Beat() {
    for (int j = 0; j < kNotesPerOctaves; j++) {
        notes_.push_back(Note());
    }
};

Beat& Beat::operator=(const Beat& beat) {
    notes_ = beat.notes_;
    return *this;
}