#include "BassCircle.h"

void BassCircle::update() {
    radius_ = Util::SmoothDamp(radius_,
        Util::GetSignificantBandsAverageFloored(fft_smoothed_, 
            fft_range_, fft_ignore_fraction_) *
        radius_factor_,
        radius_damping_factor_);
}

void BassCircle::draw() {
    int window_width = ofGetWidth();
    int window_height = ofGetHeight();

    // bass circle
    ofSetColor(255);
    ofCircle(window_width / 2, window_height / 2, radius_);
}