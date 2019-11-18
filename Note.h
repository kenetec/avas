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
   private:
	   ofSoundPlayer sound_player;
};
