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

	/*
	Pushes measure into vector
	*/
    void PushMeasure(Measure measure);

	/*
	Inserts measure into specific spot
	*/
    void InsertMeasure(Measure measure, int index);

	/*
	Clears all notes in measure
	*/
    void ClearMeasure(int index);

	/*
	Removes measure at specific index
	*/
    void RemoveMeasure(int index);

	/*
	Sets BPM of score, recalculates duration of notes
	*/
    void SetBPM(int bpm);

   private:
    std::vector<Measure> measures_;
    int bpm_;
};
