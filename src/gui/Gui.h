#pragma once

#include <ofMain.h>
#include <ofxImGui.h>

#include "MainGui.h"
#include "PianoRoll.h"

class Gui {
   public:
    void setup();
    void draw();

   private:
    ofxImGui::Gui gui_;
    MainGui main_gui_;
    PianoRoll piano_roll_;
};
