#pragma once

#include <ofMain.h>
#include <ofxImGui.h>
#include "GuiDrawer.h"
#include "../music/PlaybackEngine.h"
#include "SaveToPathModal.h"
#include "LoadSongModal.h"

class MainMenuBar {
   private:
    GuiDrawer gui_drawer_;
    PlaybackEngine* playback_engine_;
    SaveToPathModal save_to_path_modal_;
    LoadSongModal load_song_modal_;
   public:
    void setup(GuiDrawer& gui_drawer, PlaybackEngine& playback_engine);
    void draw();

   private:
    void Play();
};
