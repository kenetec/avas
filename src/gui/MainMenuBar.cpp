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
				gui_drawer_.SetWindowActive(std::string("Composer"), !gui_drawer_.IsWindowActive(std::string("Composer")));
			}
            if (ImGui::MenuItem("Piano Roll")) {
				gui_drawer_.SetWindowActive(std::string("PianoRoll"), !gui_drawer_.IsWindowActive(std::string("PianoRoll")));
            }
            ImGui::EndMenu();
		}

        ImGui::EndMainMenuBar();
    }
}