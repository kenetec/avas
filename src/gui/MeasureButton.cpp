#include "MeasureButton.h"

MeasureButton::MeasureButton(const std::string& uid, Measure* measure, PianoRoll* piano_roll)
    : uid_(uid), measure_(measure), piano_roll_(piano_roll) {
}

void MeasureButton::draw(Canvas& canvas, ImVec2 start_pos, ImVec2 size) {
    if (ImGui::InvisibleButton(uid_.c_str(), size)) {
        if (measure_ != nullptr) {
            piano_roll_->LoadMeasure(*measure_);
        }
    }
}

void MeasureButton::DrawBackgroundNotes(Canvas& canvas, ImVec2 start_pos,
                                        ImVec2 size) {}