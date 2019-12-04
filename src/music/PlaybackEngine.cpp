#include "PlaybackEngine.h"

void PlaybackEngine::Load(std::vector<std::vector<Measure>>& measures) {}

void PlaybackEngine::Play(Score& score) {
    CalculateTimeBetweenBeats();

    std::vector<MeasureContainer> measure_containers_ =
        score.GetMeasureContainers();

    for (int measure_container_index = 0; measure_container_index < measure_containers_.size(); measure_container_index++) {
        MeasureContainer measure_container = measure_containers_.at(measure_container_index);
        Instrument* instrument = measure_container.instrument;
        std::vector<Measure> measures = measure_container.measures;

		if (instrument != nullptr) {
            for (int measure_index = 0; measure_index < measures.size();
                 measure_index++) {
                Measure measure = measures.at(measure_index);
                measure_player.setup(measure, instrument, ms_between_beats_);

                measure_player.startThread();
                measure_player.waitForThread();
            }
        }
    }
}

void PlaybackEngine::PlayBeatAtSubdivisionAsync(Beat& beat) {
    std::vector<Note> notes = beat.GetNotes();
    for (int note_index = 0; note_index < notes.size(); note_index++) {
        Note* note = &notes.at(note_index);
    }
}

void PlaybackEngine::Stop() {}

void PlaybackEngine::Pause() {}

void PlaybackEngine::CalculateTimeBetweenBeats() {
    int bpm = score_.GetBPM();
    ms_between_beats_ =
        pow((double)bpm, -1) * 60000.0;  // beat/min -> min/beat * 60s/min -> 60s/beat ->
                              // s/beat * 1000ms/s -> ms/beat
}