#include "GuiDrawer.h"

GuiDrawer::GuiDrawer() {
    PianoRoll* piano_roll = new PianoRoll();
    Composer* composer = new Composer(piano_roll);

    windows.insert(
        std::pair<std::string, GuiWindow*>("PianoRoll", piano_roll));
    windows.insert(
        std::pair<std::string, GuiWindow*>("Composer", composer));
}

GuiDrawer::~GuiDrawer() {
    for (auto it = windows.cbegin(); it != windows.cend(); it++) {
        delete it->second;
    }
}

void GuiDrawer::setup() {
    for (auto it = windows.cbegin(); it != windows.cend(); it++) {
        it->second->setup();
    }
}

void GuiDrawer::draw() {
    for (auto it = windows.cbegin(); it != windows.cend(); it++) {
        GuiWindow* window = it->second;
        if (window->IsWindowActive()) {
			window->draw();
        }
    }
}

void GuiDrawer::SetWindowActive(std::string& name, bool active) {
    windows.at(name)->SetWindowActive(active);
}

bool GuiDrawer::IsWindowActive(std::string& name) {
    return windows.at(name)->IsWindowActive();
}