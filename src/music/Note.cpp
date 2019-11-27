#include "Note.h"

Note::Note() {}

Note::Note(NoteType note_type) : note_type_(note_type) {

}

void Note::Play() { sound_->play(); }