#include "Grid.h"

Grid::Grid(int n_rows, int n_cols)
    : n_rows_(n_rows), n_cols_(n_cols) {}

void Grid::draw(ImDrawList* draw_list, const ImVec2& pos, const ImVec2& size, ImGuiWindowFlags flags) {
    // set canvas vars
    canvas_.Update(draw_list, pos, size);
    vertical_divider_x_offset_ = canvas_.size.x / n_cols_;
    horizontal_divider_y_offset_ = canvas_.size.y / n_rows_;

	GenerateCellPositions();

    // draw
    DrawBackground();
    DrawDividingLines();
}

void Grid::GenerateCellPositions() {
    cell_positions_.clear();

    for (int row = 0; row < n_rows_; row++) {
        std::vector<ImVec2> row_vec;

        for (int col = 0; col < n_cols_; col++) {
            int x = vertical_divider_x_offset_ * col;
            int y = horizontal_divider_y_offset_ * row;

            row_vec.push_back(ImVec2(x, y));
        }

		cell_positions_.push_back(row_vec);
    }
}

/*
Code derived from: https://github.com/ocornut/imgui#integration
*/
void Grid::DrawBackground() {
    // inner background
    canvas_.draw_list->AddRectFilledMultiColor(
        canvas_.pos, canvas_.end_pos, background_color_ul_,
        background_color_ur_, background_color_br_, background_color_bl_);

    // border
    canvas_.draw_list->AddRect(canvas_.pos, canvas_.end_pos,
                               background_border_color_);
}

void Grid::DrawDividingLines() {
    // draw vertical
    for (int i = 0; i < n_cols_; i++) {
        int x = (vertical_divider_x_offset_ * i) + canvas_.pos.x;
        ImVec2 start_pos(x, canvas_.pos.y);
        ImVec2 end_pos(x, canvas_.end_pos.y);

        canvas_.draw_list->AddLine(start_pos, end_pos, vertical_divider_color_);
    }

    // draw horizontal
    for (int i = 0; i < n_rows_; i++) {
        int y = (horizontal_divider_y_offset_ * i) + canvas_.pos.y;
        ImVec2 start_pos(canvas_.pos.x, y);
        ImVec2 end_pos(canvas_.end_pos.x, y);

        canvas_.draw_list->AddLine(start_pos, end_pos,
                                   horizontal_divider_color_);
    }
}

void Grid::SetBackgroundColor(const ImU32& ul, const ImU32& ur, const ImU32& br,
                              const ImU32& bl) {
    background_color_ul_ = ul;
    background_color_ur_ = ur;
    background_color_br_ = br;
    background_color_bl_ = bl;
}

void Grid::SetBackgroundColor(const ImU32& color) {
    SetBackgroundColor(color, color, color, color);
}

void Grid::SetVerticalDividerColor(const ImU32& color) {
    vertical_divider_color_ = color;
}

void Grid::SetHorizontalDividerColor(const ImU32& color) {
    horizontal_divider_color_ = color;
}

void Grid::SetNumOfRows(int n_rows) { n_rows_ = n_rows; }
void Grid::SetNumOfCols(int n_cols) { n_cols_ = n_cols; }
int Grid::GetVerticalDividerXOffset() { return vertical_divider_x_offset_; }
int Grid::GetHorizontalDividerYOffset() { return horizontal_divider_y_offset_; }
int Grid::GetNumOfRows() { return n_rows_; }
int Grid::GetNumOfCols() { return n_cols_; }

ImVec2 Grid::GetCellRelativePosition(int row_index, int col_index) {
    if ((row_index >= 0 && row_index < n_rows_) &&
	(col_index >= 0 && col_index < n_cols_)) {
        return cell_positions_.at(row_index).at(col_index);
    }

	stringstream ss;
    ss << "No cell at (" << row_index << ", " << col_index << ")!";
    throw ss.str();
}

ImVec2 Grid::GetCellAbsolutePosition(int row_index, int col_index) {
    return GetCellRelativePosition(row_index, col_index) + canvas_.pos;
}

ImVec2 Grid::GetCellSize() {
    return ImVec2(vertical_divider_x_offset_, horizontal_divider_y_offset_);
}