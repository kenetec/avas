#include "Score.h"

Score::Score() {}

void Score::InsertInstrument(Instrument& instrument, int index) {
    if (index > 0 && index < measure_containers_.size()) {
        measure_containers_.at(index).instrument = &instrument;
    }
}

void Score::RemoveInstrument(int index) {
    if (index > 0 && index < measure_containers_.size()) {
        measure_containers_.at(index).instrument = nullptr;
    }
}

void Score::PushMeasureContainer() {
    PushMeasureContainer(nullptr, std::vector<Measure>());
}

void Score::PushMeasureContainer(Instrument* instrument) {
    PushMeasureContainer(instrument, std::vector<Measure>());
}

void Score::PushMeasureContainer(std::vector<Measure>& measures) {
    PushMeasureContainer(nullptr, measures);
}

void Score::PushMeasureContainer(Instrument* instrument,
                                 std::vector<Measure>& measures) {
    InstrumentScore measure_container;
    measure_container.instrument = instrument;
    measure_container.measures = measures;

    measure_containers_.push_back(measure_container);
}

InstrumentScore* Score::GetMeasureContainer(int index) {
    if (index > -1 && index < measure_containers_.size()) {
        return &measure_containers_.at(index);
    }

    stringstream ss;
    ss << "No measure containers found at " << index << " index";
    throw ss.str();
}

std::vector<InstrumentScore>& Score::GetMeasureContainers() {
    return measure_containers_;
}

void Score::SetBPM(int bpm) { bpm_ = bpm; }

int Score::GetBPM() { return bpm_; }

void Score::SetInstrumentScores(
    std::vector<InstrumentScore>& instrument_scores) {
    measure_containers_ = instrument_scores;
}