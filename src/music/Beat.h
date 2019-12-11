#pragma once

#include "Note.h"
#include <vector>

/*
Add subdivision functionality to this
*/
class Beat {
   public:
    Beat();
    Beat& Beat::operator=(const Beat& beat);
	std::vector<Note>& GetNotes() { return notes_; };
   private:
    std::vector<Note> notes_;
    const int kNotesPerOctaves = 12;
    const int kMaxOctaves = 6;
    const std::vector<std::string> kNoteNames = {
        "C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab", "A", "Bb", "B"};
};
