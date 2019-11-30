#include "PianoRoll.h"

PianoRoll::PianoRoll() { measure_ = nullptr; }

PianoRoll::~PianoRoll() {}

void PianoRoll::LoadMeasure(Measure& measure) {
    measure_ = &measure;

    // clear
    note_buttons_.clear();

    // set vars
    num_of_rows_ = Beat::kMaxNotesPerDivision;
    num_of_cols_ = measure.GetTimeSignature().beats_per_measure;
    window_size_ =
        ImVec2((kPixelsPerCol * num_of_cols_) + kNoteLabelsColWidth,
               (kPixelsPerRow * num_of_rows_) + kTimestampLabelsRowHeight - 8);

    // generate
    GenerateNoteButtons();
}

void PianoRoll::GenerateNoteButtons() {
    // sprintf_s usage from:
    // https://stackoverflow.com/questions/28963520/sprintf-command-doesnt-work
    // populate note_buttons_
    char buffer[100];
    for (int row = 0; row < num_of_rows_; row++) {
        std::vector<NoteButton> row_vec;
        for (int col = 0; col < num_of_cols_; col++) {
            sprintf_s(buffer, sizeof(buffer), "%d.%d", row, col);

            NoteButton nb =
                NoteButton(buffer, row, col, kNoteButtonDefaultColor);

            nb.SetBeat(&measure_->GetBeat(col), kBeatSubdivision);

            row_vec.push_back(nb);
        }

        note_buttons_.push_back(row_vec);
    }
}

void PianoRoll::setup() { window_active_ = true; }

void PianoRoll::draw() {
    // ImGui::StyleColorsDark();
    ImGui::SetNextWindowContentSize(window_size_);
    ImGui::SetNextWindowPos(kWindowPos, ImGuiCond_FirstUseEver);
    ImGui::Begin("Piano Roll", &window_active_,
                 ImGuiWindowFlags_AlwaysAutoResize);

    if (measure_ != nullptr) {
        {  // set variables
            canvas_.draw_list = ImGui::GetWindowDrawList();
            canvas_.pos = ImGui::GetCursorScreenPos();
            canvas_.size = ImGui::GetContentRegionAvail();
            canvas_.end_pos = canvas_.pos + canvas_.size;

            vertical_divider_x_offset_ = (int)floor(
                ((canvas_.end_pos.x - canvas_.pos.x - kNoteLabelsColWidth) /
                 num_of_cols_));

            horizontal_divider_y_offset_ =
                (int)floor(((canvas_.end_pos.y - canvas_.pos.y -
                             kTimestampLabelsRowHeight) /
                            num_of_rows_));
        }

        {  // draw
            DrawBackground();
            DrawDividingLines();
            DrawNoteNames();
            DrawTimestamps();
            DrawNoteButtons();
        }

        // canvas_.draw_list->PushClipRect(canvas_.pos, canvas_.end_pos);
    } else {
        ImGui::Text("Select a measure");
    }

    ImGui::End();
}

/*
Code derived from: https://github.com/ocornut/imgui#integration
*/
void PianoRoll::DrawBackground() {
    // inner background
    canvas_.draw_list->AddRectFilledMultiColor(
        canvas_.pos, canvas_.end_pos, IM_COL32(50, 50, 50, 255),
        IM_COL32(50, 50, 60, 255), IM_COL32(60, 60, 70, 255),
        IM_COL32(50, 50, 60, 255));

    // border
    canvas_.draw_list->AddRect(canvas_.pos, canvas_.end_pos,
                               IM_COL32(255, 255, 255, 255));
}

void PianoRoll::DrawNoteNames() {
    ImVec2 start_pos = canvas_.pos;
    ImVec2 end_pos = canvas_.pos + ImVec2(kNoteLabelsColWidth, canvas_.size.y);
    // draw background maybe?
    for (int row = 0; row < num_of_rows_; row++) {
        ImVec2 pos = ImVec2(10, (horizontal_divider_y_offset_ * row) +
                                    kTimestampLabelsRowHeight) +
                     canvas_.pos;

        canvas_.draw_list->AddText(pos, IM_COL32(255, 255, 255, 255),
                                   kNoteNames[row].c_str());
    }
}

void PianoRoll::DrawTimestamps() {
    ImVec2 start_pos = canvas_.pos;
    ImVec2 end_pos =
        canvas_.pos + ImVec2(canvas_.size.x, kTimestampLabelsRowHeight);

    // draw background ??

    char buffer[4];
    for (int col = 0; col < num_of_cols_; col++) {
        ImVec2 pos =
            ImVec2((vertical_divider_x_offset_ * col) + kNoteLabelsColWidth,
                   horizontal_divider_y_offset_ * 0.10) +
            canvas_.pos;

        sprintf_s(buffer, sizeof(buffer), "%d", (col % 4) + 1);
        canvas_.draw_list->AddText(pos, IM_COL32(255, 255, 255, 255), buffer);
    }
}

void PianoRoll::DrawDividingLines() {
    // draw vertical
    for (int i = 0; i < num_of_cols_; i++) {
        int x = (vertical_divider_x_offset_ * i) + kNoteLabelsColWidth +
                canvas_.pos.x;
        ImVec2 start_pos(x, canvas_.pos.y);
        ImVec2 end_pos(x, canvas_.end_pos.y);

        canvas_.draw_list->AddLine(start_pos, end_pos,
                                   IM_COL32(170, 170, 170, 230));
    }

    // draw horizontal
    for (int i = 0; i < num_of_rows_; i++) {
        int y = (horizontal_divider_y_offset_ * i) + kTimestampLabelsRowHeight +
                canvas_.pos.y;
        ImVec2 start_pos(canvas_.pos.x, y);
        ImVec2 end_pos(canvas_.end_pos.x, y);

        canvas_.draw_list->AddLine(start_pos, end_pos,
                                   IM_COL32(170, 170, 170, 230));
    }
}

void PianoRoll::DrawNoteButtons() {
    for (int row = 0; row < num_of_rows_; row++) {
        for (int col = 0; col < num_of_cols_; col++) {
            ImVec2 start_pos = ImVec2((vertical_divider_x_offset_ * col),
                                      (horizontal_divider_y_offset_ * row));
            ImVec2 size = ImVec2(vertical_divider_x_offset_ * (col + 1),
                                 horizontal_divider_y_offset_ * (row + 1)) -
                          start_pos - ImVec2(2, 2);

            ImVec2 cursor_pos =
                canvas_.pos + start_pos + ImVec2(1, 1) +
                ImVec2(kNoteLabelsColWidth, kTimestampLabelsRowHeight);

            ImGui::SetCursorScreenPos(cursor_pos);

            ImU32 color;
            if (col % 2 == 0) {
                color = kEvenNoteButtonColor;
            } else {
                color = kOddNoteButtonColor;
            };

            std::vector<NoteButton>* row_vec = &note_buttons_.at(row);
            NoteButton* nb = &row_vec->at(col);
            nb->draw(canvas_, cursor_pos, size, color);
        }
    }
}