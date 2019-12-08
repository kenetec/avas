#include "TailCircle.h"

void TailCircle::setup(int radius, ofPoint initial_point, ofColor color) {
    radius_ = radius;
    position_ = initial_point;
    color_ = color;
}

void TailCircle::update() { rotation_++; }

// from: https://www.youtube.com/watch?v=skYjWtm8r7I&list=PL4neAtv21WOmrV8z9rSzL20QpdLU1zJLr&index=32&t=0s
void TailCircle::draw(const std::vector<float>& fft_slice) {
    // get avg fft value
    int avg = 0;
    for (int i = 0; i < fft_slice.size(); i++) {
        avg += fft_slice.at(i);
    }
    avg /= fft_slice.size();

    // draw
    ofSetColor(color_);
    ofCircle(position_, radius_ * avg);
}