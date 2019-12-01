#pragma once

#include "Note.h"

class Beat {
   public:
    Beat() : Beat(1) {};
    Beat(int subdivisions);

	//Beat& operator=(const Beat& other){};

    /*
            Inserts note at specified index
    */
    void Insert(Note& note, int subdivision, int index);
    Note& GetNote(int subdivision, int index);

    void SetBPM(int bpm);
    void ToRest(){};

    void SetNoteActive(int subdivision, int index, bool value);
    void ToggleNoteActive(int subdivision, int index);

    void SetSubdivisions(int subdivisions);
    int GetSubdivisions() { return subdivisions_; }

	std::vector<std::vector<Note>>& GetNotes() { return notes_; };

	static const int kMaxNotesPerDivision = 12;

   private:
    int subdivisions_;
    std::vector<std::vector<Note>> notes_;
  
};
