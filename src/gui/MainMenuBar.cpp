#include "MainMenuBar.h"

void MainMenuBar::setup(GuiDrawer& gui_drawer) { gui_drawer_ = gui_drawer; }

/*
Code derived from: https://github.com/ocornut/imgui#integration
*/
void MainMenuBar::draw() {
    if (ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu("File")) {
            if (ImGui::MenuItem("Open...", "Ctrl+O")) {
            }
            if (ImGui::MenuItem("Save", "Ctrl+S")) {
            }
            if (ImGui::MenuItem("Close", "Ctrl+W")) {
            }
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("View")) {
            if (ImGui::MenuItem("Composer")) {
                gui_drawer_.ToggleWindow("Composer");
            }
            if (ImGui::MenuItem("Piano Roll")) {
                gui_drawer_.ToggleWindow("PianoRoll");
            }
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Playback")) {
            if (ImGui::MenuItem("Play")) {
                Composer* composer = reinterpret_cast<Composer*>(
                    gui_drawer_.GetWindow("Composer"));

				std::vector<std::vector<Measure>>* measures = composer->GetMeasures();

				// use playback engine to play song

            }
            ImGui::EndMenu();
        }
        
		ImGui::EndMainMenuBar();
    }
}