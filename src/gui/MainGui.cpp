#include "MainGui.h"

MainGui::~MainGui() {}

void MainGui::setup() {
    active = true;
}

/*
Code derived from: https://github.com/ocornut/imgui#integration
*/
void MainGui::draw() {
    ImGui::SetNextWindowSize(ImVec2(ofGetWidth(), 150.0f));
    ImGui::SetNextWindowPos(ImVec2(0, 0));

    ImGui::Begin("Music Editor", &active, ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoMove);

    if (ImGui::BeginMenuBar()) {
        if (ImGui::BeginMenu("File")) {
            if (ImGui::MenuItem("Open...", "Ctrl+O")) {
            }
            if (ImGui::MenuItem("Save", "Ctrl+S")) {
            }
            if (ImGui::MenuItem("Close", "Ctrl+W")) {
            }
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }

	ImDrawList *draw_list = ImGui::GetWindowDrawList();

	ImVec2 canvas_pos = ImGui::GetCursorScreenPos();
	ImVec2 canvas_size = ImGui::GetContentRegionAvail();

    ImGui::InvisibleButton("MusicRoll", ImGui::GetContentRegionAvail());

    draw_list->AddRectFilledMultiColor(
			canvas_pos,
            ImVec2(canvas_pos.x + canvas_size.x,
                    canvas_pos.y + canvas_size.y),
            IM_COL32(50, 50, 50, 255), IM_COL32(50, 50, 60, 255),
            IM_COL32(60, 60, 70, 255), IM_COL32(50, 50, 60, 255));

	 draw_list->AddRect(canvas_pos,
            ImVec2(canvas_pos.x + canvas_size.x,
                    canvas_pos.y + canvas_size.y),
            IM_COL32(255, 255, 255, 255));

	//ImGui::Separator();
 //       {
 //           static ImVector<ImVec2> points;
 //           static bool adding_line = false;
 //           ImGui::Text("Canvas example");
 //           if (ImGui::Button("Clear")) points.clear();
 //           if (points.Size >= 2) {
 //               ImGui::SameLine();
 //               if (ImGui::Button("Undo")) {
 //                   points.pop_back();
 //                   points.pop_back();
 //               }
 //           }
 //           ImGui::Text(
 //               "Left-click and drag to add lines,\nRight-click to undo");

 //           // Here we are using InvisibleButton() as a convenience to 1)
 //           // advance the cursor and 2) allows us to use IsItemHovered() But
 //           // you can also draw directly and poll mouse/keyboard by yourself.
 //           // You can manipulate the cursor using GetCursorPos() and
 //           // SetCursorPos(). If you only use the ImDrawList API, you can
 //           // notify the owner window of its extends by using
 //           // SetCursorPos(max).
 //           ImVec2 canvas_pos =
 //               ImGui::GetCursorScreenPos();  // ImDrawList API uses screen
 //                                             // coordinates!
 //           ImVec2 canvas_size =
 //               ImGui::GetContentRegionAvail();  // Resize canvas to what's
 //                                                // available
 //           if (canvas_size.x < 50.0f) canvas_size.x = 50.0f;
 //           if (canvas_size.y < 50.0f) canvas_size.y = 50.0f;
 //           draw_list->AddRectFilledMultiColor(
 //               canvas_pos,
 //               ImVec2(canvas_pos.x + canvas_size.x,
 //                      canvas_pos.y + canvas_size.y),
 //               IM_COL32(50, 50, 50, 255), IM_COL32(50, 50, 60, 255),
 //               IM_COL32(60, 60, 70, 255), IM_COL32(50, 50, 60, 255));
 //           draw_list->AddRect(canvas_pos,
 //                              ImVec2(canvas_pos.x + canvas_size.x,
 //                                     canvas_pos.y + canvas_size.y),
 //                              IM_COL32(255, 255, 255, 255));

 //           bool adding_preview = false;
 //           //ImGui::InvisibleButton("canvas", canvas_size);
 //           ImVec2 mouse_pos_in_canvas =
 //               ImVec2(ImGui::GetIO().MousePos.x - canvas_pos.x,
 //                      ImGui::GetIO().MousePos.y - canvas_pos.y);
 //           if (adding_line) {
 //               adding_preview = true;
 //               points.push_back(mouse_pos_in_canvas);
 //               if (!ImGui::IsMouseDown(0))
 //                   adding_line = adding_preview = false;
 //           }
 //           if (ImGui::IsItemHovered()) {
 //               if (!adding_line && ImGui::IsMouseClicked(0)) {
 //                   points.push_back(mouse_pos_in_canvas);
 //                   adding_line = true;
 //               }
 //               if (ImGui::IsMouseClicked(1) && !points.empty()) {
 //                   adding_line = adding_preview = false;
 //                   points.pop_back();
 //                   points.pop_back();
 //               }
 //           }
 //           draw_list->PushClipRect(
 //               canvas_pos,
 //               ImVec2(canvas_pos.x + canvas_size.x,
 //                      canvas_pos.y + canvas_size.y),
 //               true);  // clip lines within the canvas (if we resize it, etc.)
 //           for (int i = 0; i < points.Size - 1; i += 2)
 //               draw_list->AddLine(ImVec2(canvas_pos.x + points[i].x,
 //                                         canvas_pos.y + points[i].y),
 //                                  ImVec2(canvas_pos.x + points[i + 1].x,
 //                                         canvas_pos.y + points[i + 1].y),
 //                                  IM_COL32(255, 255, 0, 255), 2.0f);
 //           draw_list->PopClipRect();
 //           if (adding_preview) points.pop_back();
 //       } 


    ImGui::End();
}