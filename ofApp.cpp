#include "ofApp.h"

/*
Code derived from: https://www.youtube.com/watch?v=IiTsE7P-GDs&list=PL4neAtv21WOmrV8z9rSzL20QpdLU1zJLr&index=37&t=481s
*/

void ofApp::setup() {
    ofSetWindowTitle("AVAS");
    ofSoundStreamSetup(3, 0);  // 3 output streams, 0 input stream
    volume = 0;
    sound_player.loadSound(
        R"(C:\Users\heste\source\repos\CS126FA19\fantastic-finale-kenetec\resources\surface.mp3)");
    fftSmooth = new float[8192];

    for (int i = 0; i < 8192; i++) {
        fftSmooth[i] = 0;
    }

    bands = 64;

    sound_player.setLoop(true);
    sound_player.setVolume(0.2f);
}

void ofApp::update() {
    ofSoundUpdate();
    float* value = ofSoundGetSpectrum(bands);

    for (int i = 0; i < bands; i++) {
        fftSmooth[i] *= 0.9f;

        if (fftSmooth[i] < value[i]) {
            fftSmooth[i] = value[i];
        }
    }
}

void ofApp::draw() {
    ofSetColor(255);

    for (int i = 0; i < bands; i++) {
        ofCircle(ofGetWidth() / 2, ofGetHeight() / 2, -(fftSmooth[i] * 150));
    }
}

void ofApp::audioOut(ofSoundBuffer& out_buffer) {}

void ofApp::keyPressed(int key) {
    switch (key) {
        case '1':
            sound_player.play();
            break;
        case '2':
            sound_player.stop();
            break;
        default:
            break;
    }
}