#pragma once

#include "ofMain.h"

enum NoteType {
    SIXTEENTH,
    EIGHTH,
    QUARTER,
    HALF,
    WHOLE,
};

class Note {
   public:
    Note();
    Note(NoteType note_type);
    Note(NoteType note_type, ofSoundPlayer *sound){};
    Note(NoteType note_type, ofSoundPlayer *sound, double duration){};
    void CalculateDuration(int bpm);
    void ToRest() { sound_ = nullptr; }
    void Play();

   private:
    NoteType note_type_;
    // Points to sound loaded in SoundLoader
    ofSoundPlayer *sound_;
    double duration_;
};
