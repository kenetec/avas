#include "ofApp.h"

/*
ALL Code derived from:
https://www.youtube.com/watch?v=IiTsE7P-GDs&list=PL4neAtv21WOmrV8z9rSzL20QpdLU1zJLr&index=37&t=481s
*/

void ofApp::setup() {
    ofSetWindowTitle("AVAS");
    ofSoundStreamSetup(kDefaultOutputStreams, kDefaultInputStreams);

    main_gui_.setup();
    visualizer_.setup();

    volume = 0;
    sound_player.loadSound(
        R"(C:\Users\heste\source\repos\CS126FA19\fantastic-finale-kenetec\resources\waves.mp3)");

    sound_player_2.loadSound(
        R"(C:\Users\heste\source\repos\CS126FA19\fantastic-finale-kenetec\resources\Loop Cult - Unit 808 Sample Pack\LCU_808_samples\LCU_808_drum kits\LCU_808_drum kit 01\LCU_808_DKit_01_Crash.wav)");

    sound_player.setLoop(true);
    sound_player.setVolume(1.0f);
}

/*
ALL Code derived from:
https://www.youtube.com/watch?v=IiTsE7P-GDs&list=PL4neAtv21WOmrV8z9rSzL20QpdLU1zJLr&index=37&t=481s
*/
void ofApp::update() {
    ofSoundUpdate();
    visualizer_.update();
}

void ofApp::draw() {
    main_gui_.draw();
    visualizer_.draw();
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