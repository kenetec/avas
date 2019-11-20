#pragma once

#include <ofMain.h>

/*
Code derived from:
https://www.youtube.com/watch?v=IiTsE7P-GDs&list=PL4neAtv21WOmrV8z9rSzL20QpdLU1zJLr&index=37&t=481s
*/

class ofApp : public ofBaseApp {
   public:
    void setup();
    void update();
    void draw();
    void audioOut(ofSoundBuffer &out_buffer);
	void keyPressed(int key);
    
private:
	ofSoundPlayer sound_player;
    float *fftSmooth;
    int bands_;
    float volume;
};