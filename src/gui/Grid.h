#pragma once

#include <ofMain.h>
#include <ofxImGui.h>
#include "Canvas.h"

class Grid {
   private:
    Canvas canvas_;
    int n_cols_ = 0;
    int n_rows_ = 0;

    std::vector<std::vector<ImVec2>> cell_positions_;
    int vertical_divider_x_offset_ = 0;
    int horizontal_divider_y_offset_ = 0;

    // background colors //
    ImU32 background_color_ul_ = IM_COL32(50, 50, 50, 255);
    ImU32 background_color_ur_ = IM_COL32(50, 50, 60, 255);
    ImU32 background_color_br_ = IM_COL32(60, 60, 70, 255);
    ImU32 background_color_bl_ = IM_COL32(50, 50, 60, 255);
    ImU32 background_border_color_ = IM_COL32(225, 255, 255, 255);

    // divider colors //
    ImU32 vertical_divider_color_ = IM_COL32(170, 170, 170, 230);
    ImU32 horizontal_divider_color_ = IM_COL32(170, 170, 170, 230);

   public:
    Grid(){};
    Grid(int n_rows, int n_cols);
    void draw(ImDrawList* draw_list, const ImVec2& pos, const ImVec2& size,
              ImGuiWindowFlags flags);

    void SetBackgroundColor(const ImU32& ul, const ImU32& ur, const ImU32& br,
                            const ImU32& bl);
    void SetBackgroundColor(const ImU32& color);
    void SetVerticalDividerColor(const ImU32& color);
    void SetHorizontalDividerColor(const ImU32& color);
    void SetNumOfRows(int n_rows);
    void SetNumOfCols(int n_cols);

    int GetVerticalDividerXOffset();
    int GetHorizontalDividerYOffset();
    int GetNumOfRows();
    int GetNumOfCols();
    ImVec2 GetCellRelativePosition(int row_index, int col_index);
    ImVec2 GetCellAbsolutePosition(int row_index, int col_index);
    ImVec2 GetCellSize();

   private:
    void GenerateCellPositions();
    void DrawBackground();
    void DrawDividingLines();
};
