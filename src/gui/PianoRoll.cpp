#include "PianoRoll.h"

PianoRoll::PianoRoll() {}

PianoRoll::~PianoRoll() {
    /*for (int i = 0; i < note_buttons_.size(); i++) {
        std::vector<NoteButton*> row = note_buttons_.at(i);
        for (int j = 0; j < row.size(); j++) {
            delete row.at(j);
        }
    }*/
}

void PianoRoll::setup() {
    window_active_ = true;

	// sprintf_s usage from:
    // https://stackoverflow.com/questions/28963520/sprintf-command-doesnt-work
	// populate note_buttons_
    char buffer[100];
    for (int i = 1; i < kNumOfRows; i++) {
        std::vector<NoteButton> row;

		int note_index = i - 1;

        for (int j = 1; j < kNumOfCols; j++) {
            sprintf_s(buffer, sizeof(buffer), "%d.%d",
                              note_index, j-1);

            NoteButton nb = NoteButton(buffer, i - 1, j - 1,
                          IM_COL32(90, 90, 150, 255));

            row.push_back(nb);
        }

        note_buttons_.push_back(row);
    }
}

void PianoRoll::draw() {
    // ImGui::StyleColorsDark();
    ImGui::SetNextWindowContentSize(ImVec2(800, 316));
    ImGui::SetNextWindowPos(ImVec2(100, 300), ImGuiCond_FirstUseEver);
    ImGui::Begin("Piano Roll", &window_active_,
                 ImGuiWindowFlags_AlwaysHorizontalScrollbar);

    {  // set variables
        canvas_.draw_list = ImGui::GetWindowDrawList();
        canvas_.pos = ImGui::GetCursorScreenPos();
        canvas_.size = ImGui::GetContentRegionAvail();
        canvas_.end_pos = canvas_.pos + canvas_.size;

        vertical_divider_x_offset_ =
            ((canvas_.end_pos.x - canvas_.pos.x) / kNumOfCols);

        horizontal_divider_y_offset_ =
            ((canvas_.end_pos.y - canvas_.pos.y) / kNumOfRows);
    }

    {  // draw
        DrawBackground();
        DrawDividingLines();
        DrawNoteNames();
        DrawTimestamps();
        DrawNoteButtons();
    }

    canvas_.draw_list->PushClipRect(canvas_.pos, canvas_.end_pos);

    ImGui::End();
}

void PianoRoll::LoadMeasure(Measure& measure) {
    /*for (int beat_index = 0; beat_index < measure.GetTimeSignature().beats_per_measure; beat_index++) {
        Beat beat = measure.GetBeat(beat_index);
		
		for (int note_index = 0; note_index < Beat::kMaxNotesPerDivision;
             note_index++) {
            NoteButton* nb = note_buttons_.at(beat_index).at(note_index);
            nb->SetBeat(beat);
        }
    }*/
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

void PianoRoll::DrawDividingLines() {
    // draw vertical
    for (int i = 0; i < kNumOfCols; i++) {
        int x = (vertical_divider_x_offset_ * i) + canvas_.pos.x;
        ImVec2 start_pos(x, canvas_.pos.y);
        ImVec2 end_pos(x, canvas_.end_pos.y);

        canvas_.draw_list->AddLine(start_pos, end_pos, IM_COL32(170, 170, 170, 230));
    }

    // draw horizontal
    for (int i = 0; i < kNumOfRows; i++) {
        int y = (horizontal_divider_y_offset_ * i) + canvas_.pos.y;
        ImVec2 start_pos(canvas_.pos.x, y);
        ImVec2 end_pos(canvas_.end_pos.x, y);

        canvas_.draw_list->AddLine(start_pos, end_pos, IM_COL32(170, 170, 170, 230));
    }
}

void PianoRoll::DrawNoteNames() {
    for (int row = kNoteNamesIndexOffset; row < kNumOfRows; row++) {
        ImVec2 pos = ImVec2(vertical_divider_x_offset_ * .10,
                            horizontal_divider_y_offset_ * (row)) +
                     canvas_.pos;

        canvas_.draw_list->AddText(
            pos, IM_COL32(255, 255, 255, 255),
            kNoteNames[(int)row - kNoteNamesIndexOffset].c_str());
    }
}

void PianoRoll::DrawTimestamps() {
    char buffer[4];
    for (int col = 1; col < kNumOfCols; col++) {
        ImVec2 pos = ImVec2(vertical_divider_x_offset_ * (col),
                            horizontal_divider_y_offset_ * 0.10) +
                     canvas_.pos;

        sprintf_s(buffer, sizeof(buffer), "%d.%d",
                  (int)floor((col - 1) / 4) + 1, ((col - 1) % 4) + 1);
        canvas_.draw_list->AddText(pos, IM_COL32(255, 255, 255, 255), buffer);
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

			ImVec2 cursor_pos = canvas_.pos + start_pos + ImVec2(1, 1);
            ImGui::SetCursorScreenPos(cursor_pos);

			ImU32 color;
            if (col % 2 == 0) {
                color = IM_COL32(60, 60, 65, 255);
            } else {
                color = IM_COL32(50, 50, 55, 255);
            };

            std::vector<NoteButton>* row_vec = &note_buttons_.at((int)row - 1);
            NoteButton* nb = &row_vec->at((int)col - 1);
            nb->draw(canvas_, cursor_pos, size, color);
        }
    }
}