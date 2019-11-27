#pragma once

#include "Note.h"

class Beat {
   public:
    Beat(){};
    Beat(int subdivisions);

    /*
            Inserts note at specified index
    */
    void Insert(Note note, int index);

   private:
    int subdivisions_;
    Note *notes;
};
