#pragma once

#include <ofxImGui.h>
#include "../music/Score.h"
#include "Canvas.h"
#include "GuiWindow.h"
#include "MeasureButton.h"
#include "PianoRoll.h"
#include "Grid.h"

class Composer : public GuiWindow {
   private:
    const ImVec2 kWindowPos = ImVec2(0, 0);
    const ImVec2 kWindowSize = ImVec2(800, 300);
    
    const int kNumOfRows = 5;
    const int kNumOfCol = 5;
    const int kMeasureColStartIndex = 1;

    Canvas canvas_;
    Grid grid_;
    PianoRoll* piano_roll_;

    int vertical_divider_x_offset;
    int horizontal_divider_y_offset;

    std::vector<std::vector<MeasureButton>> measure_buttons_;
    Score score_;

   public:
    Composer(PianoRoll* piano_roll);
    ~Composer();

    Score& GetScore();

    void setup() override;
    void draw() override;

    void DrawMenuBar();
    void DrawInstruments();
    void DrawMeasures();
};