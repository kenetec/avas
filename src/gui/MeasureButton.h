#pragma once

#include <ofxImGui.h>
#include "Canvas.h"
#include "../music/Measure.h"
#include "PianoRoll.h"

class MeasureButton {
   private:
    Measure measure_;
    bool active_ = false;
    ImU32 color_;
    std::string name_;
    PianoRoll* piano_roll_;

   public:
    MeasureButton(PianoRoll* piano_roll, std::string name);
    void draw(Canvas& canvas, ImVec2 start_pos, ImVec2 size);

	void SetMeasure(Measure& measure) { measure_ = measure; };
    Measure& GetMeasure() { return measure_; };

	void SetName(std::string& name) { name_ = name; };
    std::string GetName() { return name_; };
	
	private:
    void DrawBackgroundNotes(Canvas& canvas, ImVec2 start_pos, ImVec2 size);
};
