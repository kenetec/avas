#pragma once

#include <vector>
#include "Instrument.h"

/*
Score is the top most level class for the music structure.
*/
class Score {
   public:
    Score();
   private:
    std::vector<Instrument> instruments_;
};
