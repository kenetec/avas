#include "SaveToPathModal.h"

/*
Code derived from imgui_demo.cpp
*/
void SaveToPathModal::draw(Score& score) {
    if (active_) {
        ImGui::OpenPopup("SaveToPath");
    }

    if (ImGui::BeginPopupModal("SaveToPath")) {
        ImGui::InputText(" Name", name_input_buffer_,
                         IM_ARRAYSIZE(name_input_buffer_));
        ImGui::InputText(" Save Path", path_input_buffer_, IM_ARRAYSIZE(path_input_buffer_));

        if (ImGui::Button("Save")) {
            stringstream ss;
            ss << path_input_buffer_ << "/" << name_input_buffer_ << ".json";

            Serializer::SaveScore(ss.str(), score);
            ImGui::Text("Saved!");
        }

        if (ImGui::Button("Close")) {
            ImGui::CloseCurrentPopup();
            SetActive(false);
        }

        ImGui::EndPopup();
    }
}

void SaveToPathModal::SetActive(bool active) { active_ = active; }