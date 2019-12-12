#pragma once

#pragma once

#include <ofxImGui.h>
#include "../music/Deserializer.h"
#include "../gui/Composer.h"

class LoadSongModal {
   private:
    char path_input_buffer_[128] = "";

    bool active_ = false;

   public:
    LoadSongModal(){};
    void draw(Composer* composer);
    void SetActive(bool active);
};
