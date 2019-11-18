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
   private:
	ofSoundPlayer sound_player;
    double duration;
};
