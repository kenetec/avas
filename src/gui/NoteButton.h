#pragma once

#include <ofMain.h>
#include <ofxImGui.h>

#include "../music/Beat.h"

class NoteButton {
   private:
    Beat beat_;
    bool active_ = false;
    std::string note_;
    ImU32 active_color_;

   public:
    NoteButton(std::string note, ImU32 active_color) : note_(note), active_color_(active_color){};
    void draw(ImVec2 size, ImU32 color);
    void SetActive(bool active) { active_ = active; };
    bool GetActive() { return active_; };
};