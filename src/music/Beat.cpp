#include "Beat.h"

Beat::Beat(int subdivisions) : subdivisions_(subdivisions) {
    notes_ = new Note[subdivisions];
};

void Beat::Insert(Note note, int index) {
    if (index < subdivisions_ || index >= 0) {
        notes_[index] = note;
    } else {
        throw std::out_of_range("Out of range");
    }
}

void Beat::SetBPM(int bpm) {
    for (Note note : notes_) {
        note.CalculateDuration(bpm);
    }
}