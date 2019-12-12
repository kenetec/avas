#pragma once

#include <vector>
#include "Instrument.h"

struct InstrumentScore {
    Instrument* instrument;
    std::vector<Measure> measures;
};

/*
Score is the top most level class for the music structure.
*/
class Score {
   public:
    static const int kMaxMeasures = 5;

   private:
    std::vector<InstrumentScore> measure_containers_;
    int bpm_ = 120;

   public:
    Score();

    void InsertInstrument(Instrument& instrument, int index);
    void RemoveInstrument(int index);

    void PushMeasureContainer();

    void PushMeasureContainer(Instrument* instrument);
    void PushMeasureContainer(std::vector<Measure>& measures);
    void PushMeasureContainer(Instrument* instrument,
                              std::vector<Measure>& measures);

    void InsertMeasureContainer(int index){};
    void RemoveMeasureContainer(int index){};

    InstrumentScore* GetMeasureContainer(int index);

    std::vector<InstrumentScore>& GetMeasureContainers();
    void SetBPM(int bpm_);
    int GetBPM();

    void SetInstrumentScores(std::vector<InstrumentScore>& instrument_scores);
};
