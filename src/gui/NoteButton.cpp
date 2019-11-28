#include "NoteButton.h"

void NoteButton::draw(ImVec2 size) {
    if (active_) {
        ImGui::PushStyleColor(0, ImVec4(200, 100, 150, 255));
	}

    if (ImGui::Button("", size)) {
        active_ = !active_;
    }

	ImGui::PopStyleColor();
}