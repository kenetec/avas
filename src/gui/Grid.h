#pragma once

#include <ofMain.h>
#include <ofxImGui.h>
#include "Canvas.h"

class Grid {
   private:
    Canvas canvas_;
    int pixels_per_row_;
    int pixels_per_col_;

	int num_of_cols_;
    int num_of_rows_;

	int vertical_divider_x_offset_;
    int horizontal_divider_y_offset_;

	ImU32 background_color_;
    ImU32 vertical_divider_color_;
    ImU32 horizontal_divider_color_;

   public:
    Grid();
	void draw(const ImVec2& pos, const ImVec2& size);

	void SetBackgroundColor(const ImU32& color);
    void SetVerticalDividerColor(const ImU32& color);
    void SetHorizontalDividerColor(const ImU32& color);
    void SetPixelsPerRow(int pixels_per_row);
    void SetPixelsPerCol(int pixels_per_cal);

	private:
    void DrawBackground();
    void DrawDividingLines();
};
