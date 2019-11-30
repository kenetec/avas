#include "NoteButton.h"

void NoteButton::draw(Canvas& piano_roll_canvas, ImVec2 start_pos, ImVec2 size,
                      ImU32 default_color) {
	// show activeness
	ImU32 draw_color = active_ ? active_color_ : default_color;
    piano_roll_canvas.draw_list->AddRectFilled(start_pos, start_pos + size, draw_color);

    if (ImGui::InvisibleButton(note_name_.c_str(), size)) {
        active_ = !active_;

		if (beat_ != nullptr) {
            beat_->ToggleNoteActive(0, row_);
        }
    }
}

void NoteButton::SetBeat(Beat* beat) {
    beat_ = beat;
    active_ = beat_->GetNote(0, row_).GetActive();
}