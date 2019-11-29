#include "Beat.h"

Beat::Beat(int subdivisions) : subdivisions_(subdivisions) {
    notes_ = std::vector<std::vector<Note>>();
    for (int i = 0; i < subdivisions; i++) {
        std::vector<Note> subdivision;

        for (int j = 0; j < Beat::kMaxNotesPerDivision; j++) {
            subdivision.push_back(Note());
        }

		notes_.push_back(subdivision);
    }
};

void Beat::Insert(Note& note, int subdivision, int index) {
    notes_.at(subdivision).at(index) = note;
}

Note& Beat::GetNote(int subdivision, int index) {
    return (notes_.at(subdivision).at(index));
}

void Beat::SetBPM(int bpm) {
    for (int i = 0; i < subdivisions_; i++) {
        //notes_[i].CalculateDuration(bpm);
    }
}

void Beat::SetSubdivisions(int subdivisions) {
    /*subdivisions_ = subdivisions;
    delete notes_;
    notes_ = new Note[subdivisions];*/
}

void Beat::SetNoteActive(int subdivision, int index, bool value) {
    notes_.at(subdivision).at(index).SetActive(value);
}

void Beat::ToggleNoteActive(int subdivision, int index) {
    Note* note = &notes_.at(subdivision).at(index);
    note->SetActive(!note->GetActive());
}