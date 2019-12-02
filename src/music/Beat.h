#pragma once

#include "Note.h"
#include <vector>

class Beat {
   public:
    Beat();
    Beat& Beat::operator=(const Beat& beat);
	std::vector<Note>& GetNotes() { return notes_; };
   private:
    std::vector<Note> notes_;
    const int kNotesPerOctaves = 12;
};
