#include "Beat.h"

Beat::Beat(int subdivisions) : subdivisions_(subdivisions) {
    notes = new Note[subdivisions];
};

void Beat::Insert(Note note, int index) { notes[index] = note; }