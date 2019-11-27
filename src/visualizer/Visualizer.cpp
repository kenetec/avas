#include "Visualizer.h"

/*
Code derived from:
https://www.youtube.com/watch?v=IiTsE7P-GDs&list=PL4neAtv21WOmrV8z9rSzL20QpdLU1zJLr&index=37&t=481s
*/
void Visualizer::setup() {
    fftSmooth_ = new float[kBands];

    for (int i = 0; i < kBands; i++) {
        fftSmooth_[i] = 0;
    }
}

/*
Code derived from:
https://www.youtube.com/watch?v=IiTsE7P-GDs&list=PL4neAtv21WOmrV8z9rSzL20QpdLU1zJLr&index=37&t=481s
*/
void Visualizer::update() {
    float* value = ofSoundGetSpectrum(kBands);

    for (int i = 0; i < kBands; i++) {
        fftSmooth_[i] *= kFFTSmoothFactor;

        if (fftSmooth_[i] < value[i]) {
            fftSmooth_[i] = value[i];
        }
    }
}

void Visualizer::DrawBasic2D() {
    ofSetColor(255);
    for (int i = 0; i < kBands; i++) {
        ofRectangle rect;
        rect.width = ofGetWidth() / kBands;
        rect.height = -(fftSmooth_[i] * 100);
        rect.x = (ofGetWidth() / kBands) * i;
        rect.y = ofGetHeight();

        ofDrawRectangle(rect);
    }
}

void Visualizer::draw() {

}