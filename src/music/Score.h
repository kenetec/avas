#pragma once

#include <vector>
#include "Measure.h"

/*
Score is the top most level class for the music structure.
*/
class Score {
   public:
    Score(){};
    Score(int bpm) : bpm_(bpm){};

    void PushMeasure(Measure measure);
    void InsertMeasure(Measure measure, int index);
    void ClearMeasure(int index);
    void RemoveMeasure(int index);
    void SetBPM(int bpm);

   private:
    std::vector<Measure> measures_;
    int bpm_;
};
