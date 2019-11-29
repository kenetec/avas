#pragma once
#include <math.h>
#include <ofMain.h>
#include <ofxImGui.h>
#include <vector>
#include "Canvas.h"
#include "GuiWindow.h"
#include "NoteButton.h"
#include "../music/Measure.h"

const std::vector<std::string> kNoteNames{"C",     "C#/Db", "D",     "D#/Eb",
                                          "E",     "F",     "F#/Gb", "G",
                                          "G#/Ab", "A",     "A#/Bb", "B"};

class PianoRoll : public GuiWindow {
   private:
    Canvas canvas_;

    const int kNumOfCols = 17;  // 4 beats * 4 bars + 1 extra for note names
    const int kNumOfRows = 13;  // 12 notes + 1 extra for timestamps
    int vertical_divider_x_offset_;
    int horizontal_divider_y_offset_;
    int kNoteNamesIndexOffset = kNumOfRows - 12;  // 12 notes

    std::vector<std::vector<NoteButton*>> note_buttons_;

   public:
    PianoRoll();
    ~PianoRoll();

    void setup() override;
    void draw() override;

    void LoadMeasure(Measure& measure);

   private: 
	void DrawBackground();
    void DrawDividingLines();
    void DrawNoteNames();
    void DrawTimestamps();
    void DrawNoteButtons();
};
