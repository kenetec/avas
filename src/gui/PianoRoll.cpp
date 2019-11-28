#include "PianoRoll.h"

PianoRoll::~PianoRoll() {}

void PianoRoll::setup() {
    window_active_ = true;

    for (int i = 1; i < kNumOfRows; i++) {
        for (int j = 1; j < kNumOfCols; j++) {
            //NoteButton nb(kNoteNames.at(j - 1), ImVec4(150, 150, 150, 255));
            //note_buttons_.push_back(nb);
        }
    }
}

void PianoRoll::draw() {
    // ImGui::StyleColorsDark();
    ImGui::SetNextWindowContentSize(ImVec2(800, 316));
    ImGui::SetNextWindowPos(ImVec2(100, 300), ImGuiCond_FirstUseEver);
    ImGui::Begin("Piano Roll", &window_active_,
                 ImGuiWindowFlags_AlwaysHorizontalScrollbar);

    {  // set variables
        draw_list_ = ImGui::GetWindowDrawList();
        canvas_pos_ = ImGui::GetCursorScreenPos();
        canvas_size_ = ImGui::GetContentRegionAvail();
        canvas_end_pos_ = canvas_pos_ + canvas_size_;

        vertical_divider_x_offset_ =
            ((canvas_end_pos_.x - canvas_pos_.x) / kNumOfCols);

        horizontal_divider_y_offset_ =
            ((canvas_end_pos_.y - canvas_pos_.y) / kNumOfRows);
    }

	//ImGui::PushStyleColor(0, ImVec4(200, 25, 100, 255));
 //   ImGui::Button("button", ImVec2(50, 25));
 //       ImGui::PopStyleColor();

    {  // draw
        DrawBackground();
        DrawDividingLines();
        DrawNoteNames();
        DrawTimestamps();
        DrawNoteButtons();
    }

    draw_list_->PushClipRect(canvas_pos_, canvas_end_pos_);

    ImGui::End();
}

/*
Code derived from: https://github.com/ocornut/imgui#integration
*/
void PianoRoll::DrawBackground() {
    // inner background
    draw_list_->AddRectFilledMultiColor(
        canvas_pos_, canvas_end_pos_, IM_COL32(50, 50, 50, 255),
        IM_COL32(50, 50, 60, 255), IM_COL32(60, 60, 70, 255),
        IM_COL32(50, 50, 60, 255));

    // border
    draw_list_->AddRect(canvas_pos_, canvas_end_pos_,
                       IM_COL32(255, 255, 255, 255));
}

void PianoRoll::DrawDividingLines() {
    // draw vertical
    for (int i = 0; i < kNumOfCols; i++) {
        int x = (vertical_divider_x_offset_ * i) + canvas_pos_.x;
        ImVec2 start_pos(x, canvas_pos_.y);
        ImVec2 end_pos(x, canvas_end_pos_.y);

        draw_list_->AddLine(start_pos, end_pos, IM_COL32(170, 170, 170, 230));
    }

    // draw horizontal
    for (int i = 0; i < kNumOfRows; i++) {
        int y = (horizontal_divider_y_offset_ * i) + canvas_pos_.y;
        ImVec2 start_pos(canvas_pos_.x, y);
        ImVec2 end_pos(canvas_end_pos_.x, y);

        draw_list_->AddLine(start_pos, end_pos, IM_COL32(170, 170, 170, 230));
    }
}

void PianoRoll::DrawNoteNames() {
    for (int row = kNoteNamesIndexOffset; row < kNumOfRows; row++) {
        ImVec2 pos =
            ImVec2(vertical_divider_x_offset_ * .10, horizontal_divider_y_offset_ * (row)) + canvas_pos_;

        draw_list_->AddText(pos, IM_COL32(255, 255, 255, 255),
                           kNoteNames[(int) row - kNoteNamesIndexOffset].c_str());
    }
}

void PianoRoll::DrawTimestamps() {
    char buffer[4];
    for (int col = 1; col < kNumOfCols; col++) {
        ImVec2 pos = ImVec2(vertical_divider_x_offset_ * (col),
                            horizontal_divider_y_offset_ * 0.10) +
                     canvas_pos_;

        sprintf_s(buffer, sizeof(buffer), "%d.%d", (int) floor((col - 1) / 4) + 1, ((col - 1) % 4) + 1);
        draw_list_->AddText(pos, IM_COL32(255, 255, 255, 255), buffer);
    }
}

void PianoRoll::DrawNoteButtons() {
    for (int row = 1; row < kNumOfRows; row++) {
        for (int col = 1; col < kNumOfCols; col++) {
            ImVec2 start_pos = ImVec2(vertical_divider_x_offset_ * col,
                                      horizontal_divider_y_offset_ * row);
            ImVec2 size = ImVec2(vertical_divider_x_offset_ * (col + 1),
                                 horizontal_divider_y_offset_ * (row + 1)) -
                          start_pos - ImVec2(2, 2);

            ImGui::SetCursorScreenPos(canvas_pos_ + start_pos + ImVec2(1, 1));

			ImVec4 color;
			if (col % 2 == 0) {
				color = ImVec4(200, 0, 200, 255);
            } else {
                color = ImVec4(150, 150, 150, 255);
            }

            ImGui::PushStyleColor(0, color);

            ImGui::Button("", size);

            ImGui::PopStyleColor();
        }
    }
}