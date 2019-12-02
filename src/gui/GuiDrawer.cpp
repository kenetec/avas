#include "GuiDrawer.h"

GuiDrawer::GuiDrawer() {
    PianoRoll* piano_roll = new PianoRoll();
    Composer* composer = new Composer(piano_roll);

    windows_.insert(
        std::pair<std::string, GuiWindow*>("PianoRoll", piano_roll));
    windows_.insert(
        std::pair<std::string, GuiWindow*>("Composer", composer));
}

GuiDrawer::~GuiDrawer() {
    for (auto it = windows_.begin(); it != windows_.end(); it++) {
        delete it->second;
    }
}

void GuiDrawer::setup() {
    for (auto it = windows_.begin(); it != windows_.end(); it++) {
        it->second->setup();
    }
}

void GuiDrawer::draw() {
    for (auto it = windows_.begin(); it != windows_.end(); it++) {
        GuiWindow* window = it->second;
        if (window->IsWindowActive()) {
			window->draw();
        }
    }
}

void GuiDrawer::ToggleWindow(std::string& name) {
    SetWindowActive(name, !IsWindowActive(name));
}

void GuiDrawer::SetWindowActive(std::string& name, bool active) {
    windows_.at(name)->SetWindowActive(active);
}

bool GuiDrawer::IsWindowActive(std::string& name) {
    return windows_.at(name)->IsWindowActive();
}