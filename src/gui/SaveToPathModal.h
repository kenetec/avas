#pragma once

#include <ofxImGui.h>
#include "../music/Serializer.h"

class SaveToPathModal {
   private:
    const int kInputBufferSize = 100;
    bool active_ = false;
   public:
    SaveToPathModal(){};
    void draw(Score& score);
    void SetActive(bool active);
};
