#include "MeasureButton.h"

MeasureButton::MeasureButton(PianoRoll* piano_roll, std::string name)
    : piano_roll_(piano_roll), name_(name) {
    measure_ = Measure(TimeSignature{4, NoteType::QUARTER});
}

void MeasureButton::draw(Canvas& canvas, ImVec2 start_pos, ImVec2 size) {
    if (ImGui::InvisibleButton(name_.c_str(), size)) {
        piano_roll_->LoadMeasure(measure_);
    }
}

void MeasureButton::DrawBackgroundNotes(Canvas& canvas, ImVec2 start_pos,
                                        ImVec2 size) {}