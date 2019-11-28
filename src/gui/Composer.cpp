#include "Composer.h"

void Composer::setup() { window_active_ = true; }

void Composer::draw() {
    ImGui::SetNextWindowSize(ImVec2(1000, 500.0f));
    ImGui::SetNextWindowPos(ImVec2(0, 0));

    ImGui::Begin("Composer", &window_active_, ImGuiWindowFlags_MenuBar);

    ImDrawList *draw_list = ImGui::GetWindowDrawList();

    ImVec2 canvas_pos = ImGui::GetCursorScreenPos();
    ImVec2 canvas_size = ImGui::GetContentRegionAvail();

    ImGui::InvisibleButton("Composer", canvas_size);

    draw_list->AddRectFilledMultiColor(
        canvas_pos,
        ImVec2(canvas_pos.x + canvas_size.x, canvas_pos.y + canvas_size.y),
        IM_COL32(50, 50, 50, 255), IM_COL32(50, 50, 60, 255),
        IM_COL32(60, 60, 70, 255), IM_COL32(50, 50, 60, 255));

    draw_list->AddRect(
        canvas_pos,
        ImVec2(canvas_pos.x + canvas_size.x, canvas_pos.y + canvas_size.y),
        IM_COL32(255, 255, 255, 255));

    draw_list->AddRectFilled(canvas_pos,
                             ImVec2(canvas_pos.x + (canvas_size.x / 10),
                                    canvas_pos.y + canvas_size.y),
                             IM_COL32(150, 150, 150, 255));

    draw_list->AddRectFilled(ImVec2(canvas_pos.x + 1, canvas_pos.y + 1),
                             ImVec2(canvas_pos.x + 100, canvas_pos.y + 25),
                             IM_COL32(100, 100, 100, 255));

    draw_list->AddText(ImVec2(canvas_pos.x + 25, canvas_pos.y + 5),
                       IM_COL32(125, 225, 200, 255), "A");

    for (int i = 0; i < 10; i++) {
        int x = ((canvas_size.x / 10) * i) + canvas_pos.x;
        draw_list->AddLine(ImVec2(x, canvas_pos.y),
                           ImVec2(x, canvas_pos.y + canvas_size.y),
                           IM_COL32(255, 255, 255, 100));
    }

    for (int i = 0; i < 4; i++) {
        int y = ((canvas_size.y / 4) * i) + canvas_pos.y;
        draw_list->AddLine(ImVec2(canvas_pos.x, y),
                           ImVec2(canvas_pos.x + canvas_size.x, y),
                           IM_COL32(255, 255, 255, 100));
    }

	ImGui::End();
}