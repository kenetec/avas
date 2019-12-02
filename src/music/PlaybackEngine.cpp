#include "PlaybackEngine.h"

PlaybackEngine::PlaybackEngine(SoundLoader& sound_loader) : sound_loader_(&sound_loader) {

}

void PlaybackEngine::Load(std::vector<std::vector<Measure>>& measures) {}

void PlaybackEngine::Play(std::vector<std::vector<Measure>>& all_measures) {
    for (int measure_index = 0; measure_index < all_measures.size();
         measure_index++) {
        std::vector<Measure> measures = all_measures.at(measure_index);
        for (int instrument_index = 0; instrument_index < measures.size();
             instrument_index++) {
            Measure measure = measures.at(instrument_index);
            std::vector<Beat> beats = measure.beats;

            for (int beat_index = 0; beat_index < beats.size(); beat_index++) {
                Beat beat = beats.at(beat_index);
                PlayBeatAtSubdivisionAsync(beat);
            }
        }
    }
}

void PlaybackEngine::PlayBeatAtSubdivisionAsync(Beat& beat) {
    std::vector<Note> notes = beat.GetNotes();
    for (int note_index = 0; note_index < notes.size(); note_index++) {
        Note note = notes.at(note_index);
        /*note.Play();*/
    }
}

void PlaybackEngine::Stop() {}

void PlaybackEngine::Pause() {}