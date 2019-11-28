#include "NoteButton.h"

void NoteButton::draw(ImVec2 size, ImU32 color) {
    if (active_) {
        ImGui::PushStyleColor(ImGuiCol_Button, active_color_);
    } else {
        ImGui::PushStyleColor(ImGuiCol_Button, color);
    }

    if (ImGui::Button("", size)) {
        active_ = !active_;

		std::cout << "clicked " << note_ << std::endl;
    }

    ImGui::PopStyleColor();
}