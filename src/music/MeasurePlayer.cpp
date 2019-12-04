#include "MeasurePlayer.h"

MeasurePlayer::MeasurePlayer() {}

void MeasurePlayer::setup(Measure& measure, Instrument* instrument,
                          double sleep_time_ms) {
    measure_ = measure;
    instrument_ = instrument;
    sleep_time_ms_ = sleep_time_ms;
}

void MeasurePlayer::threadedFunction() {
    std::vector<Beat> beats = measure_.beats;

    for (int beat_index = 0; beat_index < beats.size(); beat_index++) {
        Beat beat = beats.at(beat_index);
        std::vector<Note> notes = beat.GetNotes();

        for (int note_index = 0; note_index < notes.size(); note_index++) {
            Note note = notes.at(note_index);

            if (note.active) {
                ofSoundPlayer* sound =
                    instrument_->GetSound(note.note_name_str, note.octave);
                sound->play();
            }
        }

        ofSleepMillis(sleep_time_ms_);
    }
}