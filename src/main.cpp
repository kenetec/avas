#include <iostream>
#include <ofMain.h>
#include "ofApp.h"

// TODO: MAKE BIRDS IN VISUALS
// TODO: UPDATE PROPOSAL.md

/*
- DONE: REVAMP MUSIC STRUCTURE
-- DONE: MUST REWRITE INSTRUMENT CLASS
- DONE: Make playback engine play notes!!!!
-- SOUND IS NOW HERE BABY


TODOS (top = highest priority)
===============================
- VISUALS!!!!!!
	- MAKE SOMETHING INTERESTING AT THE VERY LEAST
    - Some 3D shapes would be gucci.
    - 3D particles that pulse.
    - Fractals?

- CREATE SAMPLE INSTRUMENTS
    - Synth
    - Bass
    - Piano
    - yeh

- Make MeasureButton show notes that were selected in a minature(also show selection box).

- TESTS!!!!!
	- /music
		- ScoreTest
		- PlaybackEngineTest
		- MeasurePlayerTest
	- /gui
		- NoteButton
		- MeasureButton

- Saving & Loading
========= FINISH LINE =========
- LIVE MODE (THE INITIAL IDEA BUT I ACTUALLY CAN FIGURE OUT A WAY TO DO IT)
	- KEYBOARD MAPPER
	- TIMELINE SCROLLER
	- TIME NOTIFIER
	- NOTE PLACER

- Make GUI look nice
- ...
- Tackle stretch goals
*/

int main() {
    /*ofSetupOpenGL(1280, 720, OF_WINDOW);
    ofSetFrameRate(60);*/

	ofGLFWWindowSettings settings;
    settings.setGLVersion(3, 2);  // we define the OpenGL version we want to use
    settings.setSize(1280, 720);
    ofCreateWindow(settings);

    ofRunApp(new ofApp());
}