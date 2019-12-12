#include "MainMenuBar.h"

void MainMenuBar::setup(GuiDrawer& gui_drawer,
                        PlaybackEngine& playback_engine) {
    gui_drawer_ = gui_drawer;
    playback_engine_ = &playback_engine;
}

/*
Code derived from: https://github.com/ocornut/imgui#integration
*/
void MainMenuBar::draw() {
    if (ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu("File")) {
            if (ImGui::MenuItem("Open...", "Ctrl+O")) {
                load_song_modal_.SetActive(true);
            }
            if (ImGui::MenuItem("Save", "Ctrl+S")) {
                save_to_path_modal_.SetActive(true);
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
                Play();
            }
            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();
    }

    Composer* composer =
        reinterpret_cast<Composer*>(gui_drawer_.GetWindow("Composer"));
    
    load_song_modal_.draw(composer);
    save_to_path_modal_.draw(composer->GetScore());
}

void MainMenuBar::Play() {
    Composer* composer =
        reinterpret_cast<Composer*>(gui_drawer_.GetWindow("Composer"));

    Score score = composer->GetScore();

    // use playback engine to play song
    playback_engine_->Play(score);
}