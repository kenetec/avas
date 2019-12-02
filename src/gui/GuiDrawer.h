#pragma once

#include "Composer.h"
#include "PianoRoll.h"

class GuiDrawer {
   private:
    std::map<std::string, GuiWindow*> windows_;

   public:
    GuiDrawer();
    ~GuiDrawer();
    void setup();
	void draw();

	void ToggleWindow(std::string& name);
    void SetWindowActive(std::string& name, bool active);
    bool IsWindowActive(std::string& name);
    GuiWindow* GetWindow(std::string& name) { return windows_.at(name); }

	void ToggleWindow(const char* name) { ToggleWindow(std::string(name)); }
	void SetWindowActive(const char* name, bool active) {SetWindowActive(std::string(name), active);}
    bool IsWindowActive(const char* name) {return IsWindowActive(std::string(name));}
    GuiWindow* GetWindow(const char* name) { return GetWindow(std::string(name)); }
};
