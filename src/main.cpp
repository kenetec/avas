#include <iostream>
#include <ofMain.h>
#include "ofApp.h"

// TODO: MAKE BIRDS IN VISUALS

/*
TODOS (top = highest priority):
- Make playback engine play notes!
- Make MeasureButton show notes that were selected in a minature
- VISUALS!!!
- TESTS!!!!!
	- All of the files in ./music need to be tested.
	- NoteButton and MeasureButton need to be tested.
- Make GUI look nice
- Saving & Loading
=== FINISH LINE ===
- Tackle stretch goals
*/

int main() {
    ofSetupOpenGL(1280, 720, OF_WINDOW);
    ofSetFrameRate(60);

    ofRunApp(new ofApp());
}