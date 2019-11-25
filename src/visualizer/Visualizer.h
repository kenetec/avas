#pragma once
#include <ofMain.h>

class Visualizer {
   public:
    Visualizer(){};
    void setup();
    void update();
    void draw();

   private:
    float *fftSmooth_;
    int bands_;
};