#pragma once

#include <ofMain.h>
#include <map>
#include <ofxImGui.h>

#include "gui/MainMenuBar.h"
#include "GuiDrawer.h"
#include "visualizer/Visualizer.h"

/*
ALL Code derived from:
https://www.youtube.com/watch?v=IiTsE7P-GDs&list=PL4neAtv21WOmrV8z9rSzL20QpdLU1zJLr&index=37&t=481s
*/

class ofApp : public ofBaseApp {
   public:
    void setup();
    void update();
    void draw();
    void audioOut(ofSoundBuffer &out_buffer);
	void keyPressed(int key);
    
private:
    int kDefaultOutputStreams = 3; // 3 output streams for stereo/bluetooth
    int kDefaultInputStreams = 0;

	ofxImGui::Gui imgui_;

	MainMenuBar main_menu_bar_;
	GuiDrawer gui_drawer_;
    Visualizer visualizer_;

	ofSoundPlayer sound_player;
	ofSoundPlayer sound_player_2;
    
    float volume;
};