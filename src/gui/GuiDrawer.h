#pragma once

#include "Composer.h"
#include "PianoRoll.h"

class GuiDrawer {
   private:
    std::map<std::string, GuiWindow*> windows;

   public:
    GuiDrawer();
    ~GuiDrawer();
    void setup();
	void draw();

	void SetWindowActive(std::string& name, bool active);
	bool IsWindowActive(std::string& name);
};
