#pragma once

#include <vector>
#include "Measure.h"

class Score {
   public:
    Score();

   private:
    std::vector<Measure> measures;
};
