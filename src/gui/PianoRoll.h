#pragma once
#include <ofMain.h>
#include <ofxImGui.h>

class PianoRoll {
public:
    PianoRoll(){};
	~PianoRoll();

    void setup();
    void draw();

private:
	bool window_active;
};
