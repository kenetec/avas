#pragma once

#include <ofMain.h>
#include "ofxImGui.h"

class MainGui {
   public:
    MainGui(){};
    ~MainGui();

    void setup();
    void draw();

   private:
    ofxImGui::Gui gui;
    bool active;
};
