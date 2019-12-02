#include "Grid.h"

Grid::Grid() {}

void Grid::draw(const ImVec2& pos, const ImVec2& size) {
	
}

void Grid::DrawBackground() {
	// inner background
    canvas_.draw_list->AddRectFilledMultiColor(
        canvas_.pos, canvas_.end_pos, IM_COL32(50, 50, 50, 255),
        IM_COL32(50, 50, 60, 255), IM_COL32(60, 60, 70, 255),
        IM_COL32(50, 50, 60, 255));

    // border
    canvas_.draw_list->AddRect(canvas_.pos, canvas_.end_pos,
                               IM_COL32(255, 255, 255, 255));
}

void Grid::DrawDividingLines() {
    // draw vertical
    for (int i = 0; i < num_of_cols_; i++) {
        int x = (vertical_divider_x_offset_ * i) + canvas_.pos.x;
        ImVec2 start_pos(x, canvas_.pos.y);
        ImVec2 end_pos(x, canvas_.end_pos.y);

        canvas_.draw_list->AddLine(start_pos, end_pos,
                                   IM_COL32(170, 170, 170, 230));
    }

    // draw horizontal
    for (int i = 0; i < num_of_rows_; i++) {
        int y = (horizontal_divider_y_offset_ * i) + canvas_.pos.y;
        ImVec2 start_pos(canvas_.pos.x, y);
        ImVec2 end_pos(canvas_.end_pos.x, y);

        canvas_.draw_list->AddLine(start_pos, end_pos,
                                   IM_COL32(170, 170, 170, 230));
    }
}

void Grid::SetBackgroundColor(const ImU32& color) { background_color_ = color; }

void Grid::SetVerticalDividerColor(const ImU32& color) {
    vertical_divider_color_ = color;
}

void Grid::SetHorizontalDividerColor(const ImU32& color) {
    horizontal_divider_color_ = color;
}

void Grid::SetPixelsPerRow(int pixels_per_row) {
    pixels_per_row_ = pixels_per_row;
}

void Grid::SetPixelsPerCol(int pixels_per_col) {
    pixels_per_col_ = pixels_per_col;
}