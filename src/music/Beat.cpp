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
    for (int i = 0; i < subdivisions_; i++) {
        //notes_[i].CalculateDuration(bpm);
    }
}

void Beat::SetSubdivisions(int subdivisions) {
    subdivisions_ = subdivisions;
    delete notes_;
    notes_ = new Note[subdivisions];
}