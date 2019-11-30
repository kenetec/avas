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
    const ImVec2 kWindowPos = ImVec2(100, 300);
	const int kNoteLabelsColWidth = 50;
    const int kTimestampLabelsRowHeight = 25;
	const int kPixelsPerRow = 25;
    const int kPixelsPerCol = 75;
    const int kBeatSubdivision = 0;

	const ImU32 kNoteRowLabelsBackgroundColor = IM_COL32(50, 50, 60, 255);

    const ImU32 kNoteButtonDefaultColor = IM_COL32(90, 90, 150, 255);
    const ImU32 kEvenNoteButtonColor = IM_COL32(60, 60, 65, 255);
    const ImU32 kOddNoteButtonColor = IM_COL32(50, 50, 55, 255);

	Measure* measure_;
    Canvas canvas_;
    std::vector<std::vector<NoteButton>> note_buttons_;

    ImVec2 window_size_ = ImVec2(0, 0);

    int num_of_cols_;  // 4 beats * 4 bars + 1 extra for note names
    int num_of_rows_;  // 12 notes + 1 extra for timestamps
    int vertical_divider_x_offset_;
    int horizontal_divider_y_offset_;
    //int kNoteNamesIndexOffset = num_of_rows_ - 12;  // 12 notes

   public:
    PianoRoll();
    ~PianoRoll();

	void LoadMeasure(Measure& measure);

    void setup() override;
    void draw() override;

   private: 
	void GenerateNoteButtons();

	void DrawBackground();
	void DrawNoteNames();
    void DrawTimestamps();
    void DrawDividingLines();
    void DrawNoteButtons();    
};
