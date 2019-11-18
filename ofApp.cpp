#include "ofApp.h"

// void ofApp::setup() {
//    ofSetWindowTitle("AVAS");
//    ofSoundStreamSetup(1, 0);
//}
//
// void ofApp::draw() {
//    ofBackground(ofColor::black);
//    ofSetLineWidth(5);
//    ofSetColor(ofColor::lightGreen);
//    out_line.draw();
//    ofSetColor(ofColor::cyan);
//    wave_line.draw();
//}
//
// void ofApp::audioOut(ofSoundBuffer &out_buffer) {
//    double phase = 0;
//    for (int i = 0; i < out_buffer.size(); i += 2) {
//        float sample = sin(phase);
//        out_buffer[i] = sample;
//        out_buffer[i + 1] = sample;
//        phase += 0.05;
//    }
//}

/*
 ALL Code from: https://openframeworks.cc/ofBook/chapters/sound.html
 */
void ofApp::setup() {
    phase = 0;
    updateWaveform(32);
    ofSoundStreamSetup(3, 0);  // 3 output streams, 0 input stream
    frequency = 0;
    frequencyTarget = frequency;
    volume = 0;
}

void ofApp::update() {
    ofScopedLock waveformLock(waveformMutex);
    updateWaveform(ofMap(ofGetMouseX(), 0, ofGetWidth(), 3, 64, true));
    frequency = ofLerp(frequency, frequencyTarget, 0.4);

    if (ofGetKeyPressed()) {
        volume = ofLerp(volume, 1, 0.8);  // jump quickly to 1
    } else {
        volume = ofLerp(volume, 0, 0.1);  // fade slowly to 0
    }
}

void ofApp::draw() {
    ofBackground(ofColor::black);
    ofSetLineWidth(5);
    ofSetColor(ofColor::lightGreen);
    outLine.draw();
    ofSetColor(ofColor::cyan);
    waveLine.draw();
}

void ofApp::updateWaveform(int waveformResolution) {
    waveform.resize(waveformResolution);
    waveLine.clear();

    // "waveformStep" maps a full oscillation of sin() to the size
    // of the waveform lookup table
    float waveformStep = (3.14 * 2.) / (float)waveform.size();

    for (int i = 0; i < waveform.size(); i++) {
        waveform[i] = sin(i * waveformStep);

        waveLine.addVertex(ofMap(i, 0, waveform.size() - 1, 0, ofGetWidth()),
                           ofMap(waveform[i], -1, 1, 0, ofGetHeight()));
    }
}

void ofApp::audioOut(ofSoundBuffer &out_buffer) {
    ofScopedLock waveformLock(waveformMutex);

    float sampleRate = 44100;
    float phaseStep = frequency / sampleRate;

    outLine.clear();

    for (int i = 0; i < out_buffer.size(); i += 2) {
        phase += phaseStep;
        int waveformIndex = (int)(phase * waveform.size()) % waveform.size();
        out_buffer[i] = waveform[waveformIndex] * volume;

        outLine.addVertex(ofMap(i, 0, out_buffer.size() - 1, 0, ofGetWidth()),
                          ofMap(out_buffer[i], -1, 1, 0, ofGetHeight()));
    }
}

void ofApp::keyPressed(int key) {
    if (key == 'z') {
        frequencyTarget = 261.63;  // C
    } else if (key == 'x') {
        frequencyTarget = 293.67;  // D
    } else if (key == 'c') {
        frequencyTarget = 329.63;  // E
    } else if (key == 'v') {
        frequencyTarget = 349.23;  // F
    } else if (key == 'b') {
        frequencyTarget = 392.00;  // G
    } else if (key == 'n') {
        frequencyTarget = 440.00;  // A
    } else if (key == 'm') {
        frequencyTarget = 493.88;  // B
    }
}