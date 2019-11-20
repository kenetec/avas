#include "ofApp.h"

/*
Code derived from:
https://www.youtube.com/watch?v=IiTsE7P-GDs&list=PL4neAtv21WOmrV8z9rSzL20QpdLU1zJLr&index=37&t=481s
*/

void ofApp::setup() {
    ofSetWindowTitle("AVAS");
    ofSoundStreamSetup(3, 0);  // 3 output streams for stereo/bluetooth, 0 input stream
    volume = 0;
    sound_player.loadSound(
        R"(C:\Users\heste\source\repos\CS126FA19\fantastic-finale-kenetec\resources\waves.mp3)");

	bands_ = 128;
    fftSmooth = new float[bands_];

    for (int i = 0; i < bands_; i++) {
        fftSmooth[i] = 0;
    }

    sound_player.setLoop(true);
    sound_player.setVolume(1.0f);
}

void ofApp::update() {
    ofSoundUpdate();
    float* value = ofSoundGetSpectrum(bands_);

    for (int i = 0; i < bands_; i++) {
        fftSmooth[i] *= 0.9f;

        if (fftSmooth[i] < value[i]) {
            fftSmooth[i] = value[i];
        }
    }
}

void ofApp::draw() {
    //ofSetColor(ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255)));
    ofSetColor(255);
    for (int i = 0; i < bands_; i++) {
        ofRectangle rect;
        rect.width = ofGetWidth() / bands_;
        rect.height = -(fftSmooth[i] * 100);
        rect.x = (ofGetWidth() / bands_) * i;
        rect.y = ofGetHeight();

		ofDrawRectangle(rect);
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