#include <iostream>
#include <ofMain.h>
#include "ofApp.h"

// TODO: MAKE BIRDS IN VISUALS

int main() {
    ofSetupOpenGL(640, 480, OF_WINDOW);
    ofSetFrameRate(30);

    ofRunApp(new ofApp());
}