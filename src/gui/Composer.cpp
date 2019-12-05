#include "Composer.h"

Composer::Composer(PianoRoll* piano_roll) : piano_roll_(piano_roll) {
    grid_ = Grid(kNumOfRows, kNumOfCol);

    Instrument* instrument = new Instrument(
        "Metronome",
        R"(C:\Users\heste\source\repos\CS126FA19\fantastic-finale-kenetec\test_resources\metronome)");
    instrument->Load();

    // initialize score measures
    for (int row = 0; row < kNumOfRows; row++) {
        score_.PushMeasureContainer();
        InstrumentScore* container = score_.GetMeasureContainer(row);

        container->instrument = instrument;
        std::vector<Measure>* measures = &container->measures;

        for (int col = kMeasureColStartIndex; col < kNumOfCol; col++) {
            measures->push_back(Measure());
        }
    }
}

Composer::~Composer() {}

Score& Composer::GetScore() { return score_; }

void Composer::setup() {
    window_active_ = false;

    // sprintf_s usage from:
    // https://stackoverflow.com/questions/28963520/sprintf-command-doesnt-work
    // populate MeasureButtons
    char uid_buffer[100];
    for (int row = 0; row < kNumOfRows; row++) {
        std::vector<Measure>* measures =
            &score_.GetMeasureContainer(row)->measures;
        std::vector<MeasureButton> row_vec;

        for (int col = kMeasureColStartIndex; col < kNumOfCol; col++) {
            int measure_index = col - 1;
            Measure* measure = &measures->at(measure_index);
            sprintf_s(uid_buffer, sizeof(uid_buffer), "%d.%d", row,
                      measure_index);

            row_vec.push_back(MeasureButton(uid_buffer, measure, piano_roll_));
        }
        measure_buttons_.push_back(row_vec);
    }
}

void Composer::draw() {
    ImGui::SetNextWindowSize(kWindowSize);
    ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_FirstUseEver);

    ImGui::Begin("Composer", &window_active_, ImGuiWindowFlags_MenuBar);

    {  // set variables
        canvas_.Update(ImGui::GetWindowDrawList(), ImGui::GetCursorScreenPos(),
                       ImGui::GetContentRegionAvail());

        vertical_divider_x_offset =
            (canvas_.end_pos.x - canvas_.pos.x) / kNumOfCol;

        horizontal_divider_y_offset =
            (canvas_.end_pos.y - canvas_.pos.y) / kNumOfRows;
    }

    {  // draw
        DrawMenuBar();
        grid_.draw(canvas_.draw_list, canvas_.pos, canvas_.size, NULL);
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

void Composer::DrawMenuBar() {
    if (ImGui::BeginMenuBar()) {
        if (ImGui::BeginMenu("Edit")) {
            if (ImGui::MenuItem("Add Instrument")) {
            }

            ImGui::EndMenu();
        }

        ImGui::EndMenuBar();
    }
}

void Composer::DrawInstruments() {
    for (int row = 0; row < kNumOfRows; row++) {
        ImVec2 cell_pos = grid_.GetCellRelativePosition(row, 0);
    }
}

void Composer::DrawMeasures() {
    for (int row = 0; row < kNumOfRows; row++) {
        for (int col = kMeasureColStartIndex; col < kNumOfCol; col++) {
            ImVec2 start_pos = grid_.GetCellRelativePosition(row, col);
            ImVec2 size = grid_.GetCellSize() - ImVec2(2, 2);
            ImVec2 end_pos = start_pos + size;

            ImVec2 cursor_pos =
                grid_.GetCellAbsolutePosition(row, col) + ImVec2(1, 1);
            ImGui::SetCursorScreenPos(cursor_pos);

            std::vector<MeasureButton>* row_vec = &measure_buttons_.at(row);
            MeasureButton* measure_button =
                &row_vec->at((int)col - kMeasureColStartIndex);
            measure_button->draw(canvas_, cursor_pos, size);
        }
    }
}