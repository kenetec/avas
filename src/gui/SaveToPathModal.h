#pragma once

#include <ofxImGui.h>
#include "../music/Serializer.h"

class SaveToPathModal {
   private:
    char name_input_buffer_[128] = "";
    char path_input_buffer_[128] = "";

    bool active_ = false;
   public:
    SaveToPathModal(){};
    void draw(Score& score);
    void SetActive(bool active);
};
