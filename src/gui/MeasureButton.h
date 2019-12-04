#pragma once

#include <ofxImGui.h>
#include "Canvas.h"
#include "../music/Measure.h"
#include "PianoRoll.h"

class MeasureButton {
   private:
    Measure* measure_ = nullptr;
    bool active_ = false;
    ImU32 color_;
    std::string uid_;
    PianoRoll* piano_roll_ = nullptr;

   public:
    MeasureButton(const std::string& uid, Measure* measure, PianoRoll* piano_roll);
    void draw(Canvas& canvas, ImVec2 start_pos, ImVec2 size);

	void SetMeasure(Measure* measure) { measure_ = measure; };
    Measure* GetMeasure() { return measure_; };

	void SetUID(std::string& name) { uid_ = name; };
    std::string GetUID() { return uid_; };
	
	private:
    void DrawBackgroundNotes(Canvas& canvas, ImVec2 start_pos, ImVec2 size);
};
