#pragma once

#include <ofMain.h>
#include <ofxImGui.h>

#include "PianoRoll.h"
#include "../music/Beat.h"

// forward declarations
struct PianoRollCanvas;

class NoteButton {
   private:
    Beat beat_;
    bool active_ = false;
    std::string note_;
    ImU32 active_color_;

   public:
    NoteButton(std::string note, ImU32 active_color) : note_(note), active_color_(active_color){};
    void draw(PianoRollCanvas& piano_roll, ImVec2 start_pos, ImVec2 size, ImU32 default_color);
    void SetActive(bool active) { active_ = active; };
    bool IsActive() { return active_; };
};