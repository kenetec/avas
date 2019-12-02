#pragma once
#include <math.h>
#include <ofMain.h>
#include <ofxImGui.h>
#include <vector>
#include "Canvas.h"
#include "GuiWindow.h"
#include "NoteButton.h"
#include "../music/Measure.h"
#include "../music/Instrument.h"

class PianoRoll : public GuiWindow {
   private:
    const ImVec2 kWindowPos = ImVec2(100, 300);
	const int kNoteLabelsColWidth = 50;
    const int kTimestampLabelsRowHeight = 25;
	const int kPixelsPerRow = 25;
    const int kPixelsPerCol = 75;
    const int kBeatSubdivision = 0;

    const std::vector<std::string> kNoteNames = {
        "C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab", "A", "Bb", "B"};

	const ImU32 kNoteRowLabelsBackgroundColor = IM_COL32(50, 50, 60, 255);

    const ImU32 kNoteButtonDefaultColor = IM_COL32(90, 90, 150, 255);
    const ImU32 kEvenNoteButtonColor = IM_COL32(60, 60, 65, 255);
    const ImU32 kOddNoteButtonColor = IM_COL32(50, 50, 55, 255);

	Measure* measure_;
    Canvas canvas_;
    std::vector<std::vector<NoteButton>> note_buttons_;

    ImVec2 window_size_ = ImVec2(0, 0);

    int num_of_cols_;
    int num_of_rows_ = Instrument::kNotesPerOctaves * Instrument::kMaxOctaves;
    int vertical_divider_x_offset_;
    int horizontal_divider_y_offset_;

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
