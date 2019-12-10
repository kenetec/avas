#include "Particle.h"

void Particle::setup(float* fft_smoothed, ofColor default_color, Range range, ofPoint initial_point) {
    ReactiveObject::setup(fft_smoothed);

	default_color_ = default_color;
    range_ = range;
    position_ = initial_point;
}


void Particle::update() {}

/*
code derived from:
https://www.youtube.com/watch?v=wkOppaMIsbw&list=PL4neAtv21WOmrV8z9rSzL20QpdLU1zJLr&index=40
*/
void Particle::draw() { 
	float time = ofGetElapsedTimef();
    float x = ofGetWidth() * ofNoise(time * speed_ + position_.x);
    float y = ofGetHeight() * ofNoise(time * speed_ + position_.y);

    float radius = Util::SmoothDamp(
        radius_, max_radius_ * Util::GetAverageOfBandValuesOverThreshold(
                                 fft_smoothed_, range_, 0), kSmoothingFactor);

    radius_ = radius;

    ofSetColor(default_color_);
    ofCircle(x, y, radius_);
}