#include "Composer.h"

Composer::~Composer() {
    for (int row = 0; row < kNumOfRows; row++) {
        for (int col = 1; col < kNumOfCol; col++) {
            delete measure_buttons_.at(row).at((int)col-1);
        }
    }
}

void Composer::setup() {
    window_active_ = true;

	// sprintf_s usage from: https://stackoverflow.com/questions/28963520/sprintf-command-doesnt-work
    // populate measures
    char buffer[100];
    for (int row = 0; row < kNumOfRows; row++) {
        std::vector<MeasureButton*> row_vec;
        for (int col = 1; col < kNumOfCol; col++) {
            sprintf_s(buffer, sizeof(buffer), "%d.%d", row, col);

            row_vec.push_back(new MeasureButton(piano_roll_, buffer));
        }
        measure_buttons_.push_back(row_vec);
    }
}

void Composer::draw() {
    ImGui::SetNextWindowSize(ImVec2(800, 500.0f));
    ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_FirstUseEver);

    ImGui::Begin("Composer", &window_active_, ImGuiWindowFlags_MenuBar);

    {  // set variables
        canvas_.draw_list = ImGui::GetWindowDrawList();
        canvas_.pos = ImGui::GetCursorScreenPos();
        canvas_.size = ImGui::GetContentRegionAvail();
        canvas_.end_pos = canvas_.pos + canvas_.size;

        vertical_divider_x_offset =
            (canvas_.end_pos.x - canvas_.pos.x) / kNumOfCol;

        horizontal_divider_y_offset =
            (canvas_.end_pos.y - canvas_.pos.y) / kNumOfRows;
    }

    {  // draw
        DrawBackground();
        DrawTimeline();
        DrawLines();
        DrawMeasures();
    }

    ImGui::InvisibleButton("Composer", canvas_.size);

    /*draw_list->AddRectFilled(canvas_.pos,
                             ImVec2(canvas_.pos.x + (canvas_.size.x / 10),
                                    canvas_.pos.y + canvas_.size.y),
                             IM_COL32(150, 150, 150, 255));

    draw_list->AddRectFilled(ImVec2(canvas_.pos.x + 1, canvas_.pos.y + 1),
                             ImVec2(canvas_.pos.x + 100, canvas_.pos.y + 25),
                             IM_COL32(100, 100, 100, 255));

    draw_list->AddText(ImVec2(canvas_.pos.x + 25, canvas_.pos.y + 5),
                       IM_COL32(125, 225, 200, 255), "A");*/

    ImGui::End();
}

/*
Code derived from: https://github.com/ocornut/imgui#integration
*/
void Composer::DrawBackground() {
    canvas_.draw_list->AddRectFilledMultiColor(
        canvas_.pos,
        ImVec2(canvas_.pos.x + canvas_.size.x, canvas_.pos.y + canvas_.size.y),
        IM_COL32(50, 50, 50, 255), IM_COL32(50, 50, 60, 255),
        IM_COL32(60, 60, 70, 255), IM_COL32(50, 50, 60, 255));

    canvas_.draw_list->AddRect(
        canvas_.pos,
        ImVec2(canvas_.pos.x + canvas_.size.x, canvas_.pos.y + canvas_.size.y),
        IM_COL32(255, 255, 255, 255));
}

void Composer::DrawTimeline() {}

void Composer::DrawLines() {
    // draw vertical dividers
    for (int i = 0; i < kNumOfCol; i++) {
        int x = (vertical_divider_x_offset * i) + canvas_.pos.x;
        canvas_.draw_list->AddLine(ImVec2(x, canvas_.pos.y),
                                   ImVec2(x, canvas_.pos.y + canvas_.size.y),
                                   IM_COL32(255, 255, 255, 100));
    }

    // draw horizontal dividers
    for (int i = 0; i < kNumOfRows; i++) {
        int y = (horizontal_divider_y_offset * i) + canvas_.pos.y;
        canvas_.draw_list->AddLine(ImVec2(canvas_.pos.x, y),
                                   ImVec2(canvas_.pos.x + canvas_.size.x, y),
                                   IM_COL32(255, 255, 255, 100));
    }
}

void Composer::DrawMeasures() {
    for (int row = 0; row < kNumOfRows; row++) {
        for (int col = 1; col < kNumOfCol; col++) {
            ImVec2 start_pos = ImVec2((vertical_divider_x_offset * col),
                                      (horizontal_divider_y_offset * row));
            ImVec2 end_pos = ImVec2(vertical_divider_x_offset * (col + 1),
                                    horizontal_divider_y_offset * (row + 1)) +
                             start_pos;

            ImVec2 size = ImVec2(vertical_divider_x_offset * (col + 1),
                                 horizontal_divider_y_offset * (row + 1)) -
                          start_pos - ImVec2(2, 2);

			ImVec2 cursor_pos = canvas_.pos + start_pos + ImVec2(1, 1);
            ImGui::SetCursorScreenPos(cursor_pos);
            
			std::vector<MeasureButton*> row_vec = measure_buttons_.at(row);
            MeasureButton* measure_button = row_vec.at((int)col - 1);
            measure_button->draw(canvas_, cursor_pos, size);
        }
    }
}