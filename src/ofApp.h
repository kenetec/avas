#pragma once

#include "ofMain.h"

//class ofApp : public ofBaseApp {
//   private:
//    ofPolyline out_line;
//    ofPolyline wave_line;
//   public:
//    void setup();
//    void draw();
//    void audioOut(ofSoundBuffer &out_buffer);
//};

/*
 ALL Code from: https://openframeworks.cc/ofBook/chapters/sound.html
 */

class ofApp : public ofBaseApp {
   public:
    void setup();
    void update();
    void draw();

    void updateWaveform(int waveformResolution);
    void audioOut(ofSoundBuffer &out_buffer);
	
	void keyPressed(int key);
    float frequencyTarget;

    std::vector<float> waveform;  // this is the lookup table
    double phase;
    float frequency;

    ofMutex waveformMutex;
    ofPolyline waveLine;
    ofPolyline outLine;
    float volume;
};