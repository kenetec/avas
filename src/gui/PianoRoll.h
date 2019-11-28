#pragma once
#include <ofMain.h>
#include <ofxImGui.h>
#include <vector>
#include <math.h>
#include "NoteButton.h"

class PianoRoll {
   private:
    bool window_active_;

    ImVec2 canvas_pos_;
    ImVec2 canvas_size_;
    ImVec2 canvas_end_pos_;
    ImDrawList* draw_list_;

    int kNumOfCols = 17; // 4 beats * 4 bars + 1 extra for note names
    int kNumOfRows = 13;  // 12 notes + 1 extra for timestamps
    int vertical_divider_x_offset_;
    int horizontal_divider_y_offset_;
    int kNoteNamesIndexOffset = kNumOfRows - 12; // 12 notes

	std::vector<std::string> kNoteNames = {
		"C", "C#/Db", 
		"D", "D#/Eb",
		"E",
		"F", "F#/Gb",
		"G", "G#/Ab",
		"A", "A#/Bb",
		"B"
	};

	std::vector<std::vector<NoteButton>> note_buttons_;

   public:
    PianoRoll(){};
	~PianoRoll();

    void setup();
    void draw();

   private:
    void DrawBackground();
    void DrawDividingLines();
    void DrawNoteNames();
    void DrawTimestamps();
    void DrawNoteButtons();
};
