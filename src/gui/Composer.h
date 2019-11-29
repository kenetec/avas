#pragma once

#include <ofxImGui.h>
#include "GuiWindow.h"
#include "Canvas.h"
#include "MeasureButton.h"
#include "PianoRoll.h"

class Composer : public GuiWindow {
   private:
    const int kNumOfRows = 5;
    const int kNumOfCol = 5;

	Canvas canvas_;

	int vertical_divider_x_offset;
    int horizontal_divider_y_offset;

	std::vector<std::vector<MeasureButton*>> measure_buttons_;
    PianoRoll* piano_roll_;
   public:
    Composer(PianoRoll* piano_roll) : piano_roll_(piano_roll){};
    ~Composer();

    void setup() override;
    void draw() override;

	void DrawBackground();
    void DrawTimeline();
	void DrawLines();
    void DrawMeasures();
};