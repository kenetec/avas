#include "MainGui.h"

MainGui::~MainGui() { gui.exit(); }

void MainGui::setup() {
    gui.setup();
    active = true;
}

/*
Code derived from: https://github.com/ocornut/imgui#integration
*/
void MainGui::draw() {
    gui.begin();
    ImGui::Begin("Music Editor", &active, ImGuiWindowFlags_MenuBar);

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

    ImGui::Text("Hello World!");

    ImGui::End();
    gui.end();
}