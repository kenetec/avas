#include "Beat.h"

Beat::Beat(int subdivisions) : subdivisions_(subdivisions) {
    notes = new Note[subdivisions];
};

void Beat::Insert(Note note, int index) {
    if (index < subdivisions_ || index >= 0) {
        notes[index] = note;
    } else {
        throw std::out_of_range("Out of range");
    }
}