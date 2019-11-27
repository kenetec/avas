#include "PianoRoll.h"

PianoRoll::~PianoRoll() {}

void PianoRoll::setup() { window_active = true; }

void PianoRoll::draw() {
    // ImGui::StyleColorsDark();
    // ImGui::SetNextWindowContentSize(ImVec2(ofGetWidth(), 300));
    ImGui::SetNextWindowPos(ImVec2(100, 300), ImGuiCond_FirstUseEver);
    ImGui::Begin("Piano Roll", &window_active,
                 ImGuiWindowFlags_AlwaysHorizontalScrollbar);

		
    if (ImGui::Button("button", ImVec2(50, 20))) {
        std::cout << "button pressed" << std::endl;
    }


    // ImGui::InvisibleButton("note_1", ImVec2(50, 20));
    ImDrawList *draw_list = ImGui::GetWindowDrawList();
    draw_list->AddRectFilled(ImGui::GetCursorScreenPos(), ImGui::GetContentRegionAvail(), IM_COL32(255, 0, 255, 64));
    draw_list->PushClipRect(ImGui::GetCursorScreenPos(),
                            ImGui::GetContentRegionAvail());

    ImGui::End();
}