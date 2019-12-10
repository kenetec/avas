#pragma once

#include <ofMain.h>
#include <ofUtils.h>

#include "ReactiveObject.h"
#include "Util.h"

class Particle : public ReactiveObject {
   private:
    ofColor default_color_;
    ofPoint position_;
    Range range_;

    float max_radius_ = 400;
    float radius_ = 0;
    float speed_ = .1;

    const int kNumOfBands = 512;
    const double kSmoothingFactor = 0.9;
   public:
    Particle(){};
    void setup(float* fft_smoothed, ofColor default_color, Range range,
               ofPoint initial_position);
    void update();
    void draw();
};
