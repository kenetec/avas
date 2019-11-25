#include "Visualizer.h"

/*
Code derived from:
https://www.youtube.com/watch?v=IiTsE7P-GDs&list=PL4neAtv21WOmrV8z9rSzL20QpdLU1zJLr&index=37&t=481s
*/
void Visualizer::setup() {
    bands_ = 128;
    fftSmooth_ = new float[bands_];

    for (int i = 0; i < bands_; i++) {
        fftSmooth_[i] = 0;
    }
}

/*
Code derived from:
https://www.youtube.com/watch?v=IiTsE7P-GDs&list=PL4neAtv21WOmrV8z9rSzL20QpdLU1zJLr&index=37&t=481s
*/
void Visualizer::update() {
    float* value = ofSoundGetSpectrum(bands_);

    for (int i = 0; i < bands_; i++) {
        fftSmooth_[i] *= 0.9f;

        if (fftSmooth_[i] < value[i]) {
            fftSmooth_[i] = value[i];
        }
    }
}

void Visualizer::draw() {
    ofSetColor(255);
    for (int i = 0; i < bands_; i++) {
        ofRectangle rect;
        rect.width = ofGetWidth() / bands_;
        rect.height = -(fftSmooth_[i] * 100);
        rect.x = (ofGetWidth() / bands_) * i;
        rect.y = ofGetHeight();

        ofDrawRectangle(rect);
    }
}