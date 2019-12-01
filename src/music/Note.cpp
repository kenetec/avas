#include "Note.h"

Note::Note() {
    note_type_ = NoteType::QUARTER;
    sound_ = nullptr;
}

Note::Note(NoteType note_type) : Note() { note_type_ = note_type; }

Note::Note(NoteType note_type, ofSoundPlayer* sound) : Note(note_type) {
    sound_ = sound;
}

void Note::Play() {
    if (sound_ != nullptr) {
        sound_->play();
    }
}