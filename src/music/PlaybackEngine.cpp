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
            std::vector<Beat> beats = measure.GetBeats();

            for (int beat_index = 0; beat_index < beats.size(); beat_index++) {
                Beat beat = beats.at(beat_index);
                int subdivisions = beat.GetSubdivisions();

                for (int subdivision_index = 0;
                     subdivision_index < subdivisions; subdivision_index++) {
                    // void (PlaybackEngine::* func)(Beat&, int) =
                    // &this->PlayBeatAtSubdivisionAsync;
                    /*std::thread play_thread(
                        [](Beat& beat, int subdivision) {
                            std::vector<std::vector<Note>> all_notes =
                                beat.GetNotes();
                            std::vector<Note> notes = all_notes.at(subdivision);
                            for (int note_index = 0; note_index < notes.size();
                                 note_index++) {
                                Note note = notes.at(note_index);
                                note.Play();
                            }
                        },
                        beat, subdivision_index);*/
                    PlayBeatAtSubdivisionAsync(beat, subdivision_index);
                }
            }
        }
    }
}

void PlaybackEngine::PlayBeatAtSubdivisionAsync(Beat& beat, int subdivision) {
    std::vector<std::vector<Note>> all_notes = beat.GetNotes();
    std::vector<Note> notes = all_notes.at(subdivision);
    for (int note_index = 0; note_index < notes.size(); note_index++) {
        Note note = notes.at(note_index);
        note.Play();
    }
}

void PlaybackEngine::Stop() {}

void PlaybackEngine::Pause() {}