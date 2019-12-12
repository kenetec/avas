#include "LoadSongModal.h"

/*
Code derived from imgui_demo.cpp
*/
void LoadSongModal::draw(Composer* composer) {
    if (active_) {
        ImGui::OpenPopup("Load Song");
    }

    if (ImGui::BeginPopupModal("Load Song")) {
        ImGui::InputText(" Load Path", path_input_buffer_,
                         IM_ARRAYSIZE(path_input_buffer_));

        if (ImGui::Button("Load")) {
            composer->SetScore(Deserializer::LoadScore(path_input_buffer_));
            ImGui::Text("Loaded!");
        }

        if (ImGui::Button("Close")) {
            ImGui::CloseCurrentPopup();
            SetActive(false);
        }

        ImGui::EndPopup();
    }
}

void LoadSongModal::SetActive(bool active) { active_ = active; }