#pragma once

#include <ofMain.h>
#include "ofxImGui.h"
#include "PianoRoll.h"

class MainGui {
   public:
    MainGui(){};
    ~MainGui();

    void setup();
    void draw();

   private:
    //PianoRoll piano_roll_;
    bool active;
};
