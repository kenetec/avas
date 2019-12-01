#pragma once

#include <ofMain.h>
#include <ofxImGui.h>
#include "GuiDrawer.h"
#include "../music/PlaybackEngine.h"

class MainMenuBar {
   private:
    GuiDrawer gui_drawer_;
    PlaybackEngine* playback_engine_;
   public:
    void setup(GuiDrawer& gui_drawer, PlaybackEngine& playback_engine);
    void draw();
};
