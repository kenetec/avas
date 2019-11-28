#pragma once

#include <ofMain.h>
#include <ofxImGui.h>
#include "GuiDrawer.h"

class MainMenuBar {
   private:
    GuiDrawer gui_drawer_;
   public:
    void setup(GuiDrawer& gui_drawer);
    void draw();
};
