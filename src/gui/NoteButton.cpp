#include "NoteButton.h"

void NoteButton::draw(PianoRollCanvas& canvas, ImVec2 start_pos, ImVec2 size, ImU32 default_color) {
	ImU32 draw_color = active_ ? active_color_ : default_color;
	canvas.draw_list->AddRectFilled(start_pos, start_pos + size, draw_color);

    if (ImGui::InvisibleButton(note_.c_str(), size)) {
        active_ = !active_;
    }
}