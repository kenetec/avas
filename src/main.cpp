#include <iostream>
#include <ofMain.h>
#include "ofApp.h"

// TODO: MAKE BIRDS IN VISUALS

int main() {
    ofSetupOpenGL(1280, 720, OF_WINDOW);
    ofSetFrameRate(30);

    ofRunApp(new ofApp());
}