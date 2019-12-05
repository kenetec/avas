#include "PlaybackEngine.h"

PlaybackEngine::~PlaybackEngine() {}

void PlaybackEngine::Load(std::vector<std::vector<Measure>>& measures) {}

void PlaybackEngine::Play(Score& score) {
    CalculateTimeBetweenBeats();

    std::vector<InstrumentScore> measure_containers_ = score.GetMeasureContainers();

    for (int measure_container_index = 0; measure_container_index < measure_containers_.size(); measure_container_index++) {
        InstrumentScore instrument_score = measure_containers_.at(measure_container_index);
        std::shared_ptr<InstrumentScorePlayer> instrument_score_player =
            std::shared_ptr<InstrumentScorePlayer>(new InstrumentScorePlayer());

		instrument_score_players_.push_back(instrument_score_player);

        instrument_score_player->setup(instrument_score, ms_between_beats_);
        instrument_score_player->startThread();
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