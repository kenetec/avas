#pragma once

#include <ofMain.h>
#include <ofxImGui.h>

#include "../music/Beat.h"

class NoteButton {
   private:
    Beat beat_;
    bool active_ = false;
    std::string note_;
    ImVec4 default_color_;

   public:
    NoteButton(std::string note, ImVec4 default_color) : note_(note), default_color_(default_color){};
    void draw(ImVec2 size);
    void SetActive(bool active) { active_ = active; };
    bool GetActive() { return active_; };
};