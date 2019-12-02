#include <iostream>
#include <ofMain.h>
#include "ofApp.h"

// TODO: MAKE BIRDS IN VISUALS
// TODO: UPDATE PROPOSAL.md

/*
TODOS (top = highest priority)
===============================
- DONE: REVAMP MUSIC STRUCTURE +
- Make playback engine play notes!!!!
- Make MeasureButton show notes that were selected in a minature(also show selection box).
- VISUALS!!!!!!
	- Some 3D shapes would be gucci.
	- 3D particles that pulse.
	- Fractals?
- TESTS!!!!!
	- All of the classes in ./music need to be tested.
	- NoteButton and MeasureButton need to be tested.
- Saving & Loading
========= FINISH LINE =========
- Make GUI look nice
- Tackle stretch goals
*/

int main() {
    ofSetupOpenGL(1280, 720, OF_WINDOW);
    ofSetFrameRate(60);

    ofRunApp(new ofApp());
}