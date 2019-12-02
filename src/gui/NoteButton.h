#pragma once

#include <ofMain.h>
#include <ofxImGui.h>
#include "../music/Beat.h"
#include "Canvas.h"

class NoteButton {
   private:
    Note* note_;
    std::string uid_;
    ImU32 active_color_;
    int row_;
    int col_;

   public:
    NoteButton(const std::string& uid, Note& note, int row, int col, ImU32 active_color);
    void draw(Canvas& piano_roll_canvas, ImVec2 start_pos, ImVec2 size, ImU32 default_color);

    void SetNote(Note* note);
    Note* GetNote();
};