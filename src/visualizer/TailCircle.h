#pragma once
#include <ofMain.h>

class TailCircle {
   private:
    int radius_ = 0;
    int rotation_ = 0;
    ofPoint position_;
    ofColor color_;

   public:
    TailCircle(){};
    void setup(int radius, ofPoint initial_point, ofColor color);
    void update();
    void draw(const std::vector<float>& fft_slice);
};