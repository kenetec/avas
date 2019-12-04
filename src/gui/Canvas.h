#pragma once

#include <ofxImGui.h>

struct Canvas {
    ImVec2 pos;
    ImVec2 size;
    ImVec2 end_pos;
    ImDrawList* draw_list = nullptr;

	Canvas(){};
	Canvas(const Canvas& canvas) : draw_list(canvas.draw_list), pos(canvas.pos), size(canvas.size), end_pos(canvas.end_pos){}

	void Update(ImDrawList* draw_list, ImVec2 pos, ImVec2 size) {
        this->draw_list = draw_list;
        this->pos = pos;
        this->size = size;
        this->end_pos = pos + size;
	}
};