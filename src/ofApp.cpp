#include "ofApp.h"

ofApp::ofApp() {}

/*
Code derived from:
https://www.youtube.com/watch?v=IiTsE7P-GDs&list=PL4neAtv21WOmrV8z9rSzL20QpdLU1zJLr&index=37&t=481s
*/
void ofApp::setup() {
    ofSetWindowTitle("AVAS");
    ofSoundStreamSetup(kDefaultOutputStreams, kDefaultInputStreams);

    // ripped from: serious-snakes assignment
    srand(static_cast<unsigned>(time(0)));

	imgui_.setup();
    gui_drawer_.setup();
    main_menu_bar_.setup(gui_drawer_, playback_engine_);
    visualizer_.setup();

    volume = 0;

    sound_player.loadSound(
        R"(C:\Users\heste\source\repos\CS126FA19\fantastic-finale-kenetec\resources\songs\Danger - 624.mp3)");

    sound_player_2.loadSound(
        R"(C:\Users\heste\source\repos\CS126FA19\fantastic-finale-kenetec\resources\Loop Cult - Unit 808 Sample Pack\LCU_808_samples\LCU_808_drum kits\LCU_808_drum kit 01\LCU_808_DKit_01_Crash.wav)");

    sound_player.setLoop(true);
    sound_player.setVolume(1.0f);
}


void ofApp::update() {
    ofSoundUpdate();
    visualizer_.update();
}

void ofApp::draw() {
    visualizer_.draw();
    visualizer_.DrawBasic2D();

    imgui_.begin();

    main_menu_bar_.draw();
    gui_drawer_.draw();
    ImGui::ShowDemoWindow();

    imgui_.end();
}

void ofApp::audioOut(ofSoundBuffer& out_buffer) {}

void ofApp::keyPressed(int key) {
    switch (key) {
        case '1':
            sound_player.play();
            break;
        case '2':
            sound_player.stop();
            break;
        case 'z':
            sound_player_2.play();
            break;
        default:
            break;
    }
}