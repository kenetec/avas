#pragma once
#include <ofMain.h>

class Visualizer {
   public:
    Visualizer(){};
    void setup();
    void update();
    void draw();

   private:
    /*
	Code derived from:
	https://www.youtube.com/watch?v=IiTsE7P-GDs&list=PL4neAtv21WOmrV8z9rSzL20QpdLU1zJLr&index=37&t=481s
	*/
    float *fftSmooth_;
    int bands_;
};