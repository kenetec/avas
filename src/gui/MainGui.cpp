#include "MainGui.h"

MainGui::~MainGui() { gui.exit(); }

void MainGui::setup() { gui.setup(); }

void MainGui::draw() {
    gui.begin();

	ImGui::Text("Hello World!");

	gui.end();
}