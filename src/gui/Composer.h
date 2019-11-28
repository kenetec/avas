#pragma once

#include <ofxImGui.h>
#include "GuiWindow.h"

class Composer : public GuiWindow {
   public:
    void setup() override;
    void draw() override;
};