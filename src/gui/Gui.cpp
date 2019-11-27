#include "Gui.h"

void Gui::setup() {
    gui_.setup();

    main_gui_.setup();
    piano_roll_.setup();
}

void Gui::draw() {
    gui_.begin();

    main_gui_.draw();
    piano_roll_.draw();

    gui_.end();
}