#pragma once

#include <ofMain.h>
#include <ofxImGui.h>
#include "../music/Beat.h"
#include "Canvas.h"

class NoteButton {
   private:
    Beat* beat_;
    bool active_ = false;
    std::string note_name_;
    ImU32 active_color_;
    int row_;
    int col_;
	int subdivision_;

   public:
    NoteButton(std::string note_name, int row, int col, ImU32 active_color)
        : note_name_(note_name),
          row_(row),
          col_(col),
          active_color_(active_color) {
        beat_ = nullptr;
    };

    void draw(Canvas& piano_roll_canvas, ImVec2 start_pos, ImVec2 size, ImU32 default_color);

    void SetBeat(Beat* beat, int subdivision_);
    Note& GetNote() { return beat_->GetNote(0, row_); };
    void SetActive(bool active) { active_ = active; };
    bool IsActive() { return active_; };
};