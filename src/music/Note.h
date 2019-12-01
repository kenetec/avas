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
    Note(NoteType note_type, ofSoundPlayer *sound);
    void Play();
    //void CalculateDuration(int bpm);
    void ToRest() { sound_ = nullptr; }

	void SetSound(ofSoundPlayer *sound) { sound_ = sound; };
    ofSoundPlayer* GetSound() { return sound_; };

    void SetActive(bool active) {active_ = active;};
    bool GetActive() { return active_; };

   private:
    NoteType note_type_;
    // Points to sound loaded in SoundLoader
    ofSoundPlayer *sound_;
    double duration_;
    bool active_ = false;
};
