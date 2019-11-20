#include <iostream>
#include <ofMain.h>
#include "ofApp.h"

int main() {
    ofSetupOpenGL(640, 480, OF_WINDOW);
    ofSetFrameRate(30);

    ofRunApp(new ofApp());
}