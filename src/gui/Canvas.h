#pragma once

#include <ofxImGui.h>

struct Canvas {
    ImVec2 pos;
    ImVec2 size;
    ImVec2 end_pos;
    ImDrawList* draw_list;
};