#include "NoteButton.h"

NoteButton::NoteButton(const std::string& uid, Note& note, int row, int col, ImU32 active_color)
    : uid_(uid),
      note_(&note),
      row_(row),
      col_(col),
      active_color_(active_color) {
};

void NoteButton::draw(Canvas& piano_roll_canvas, ImVec2 start_pos, ImVec2 size,
                      ImU32 default_color) {
	// show activeness
	ImU32 draw_color = note_->active ? active_color_ : default_color;
    piano_roll_canvas.draw_list->AddRectFilled(start_pos, start_pos + size, draw_color);

    if (ImGui::InvisibleButton(uid_.c_str(), size)) {
		note_->active = !note_->active;
    }
}

void NoteButton::SetNote(Note* note) {
    note_ = note;
}

Note* NoteButton::GetNote() { return note_; }