#include "SaveToPathModal.h"

/*
Code derived from imgui_demo.cpp
*/
void SaveToPathModal::draw(Score& score) {
    if (active_) {
        ImGui::OpenPopup("SaveToPath");
    }

    if (ImGui::BeginPopupModal("SaveToPath")) {
        char* input_buffer = new char[kInputBufferSize];

        ImGui::InputText("Save Path: ", input_buffer, kInputBufferSize);

        if (ImGui::Button("Save")) {
            Serializer::SaveScore(input_buffer, score);
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