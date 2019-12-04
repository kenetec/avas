#include "ofApp.h"

ofApp::ofApp() {}

/*
Code derived from:
https://www.youtube.com/watch?v=IiTsE7P-GDs&list=PL4neAtv21WOmrV8z9rSzL20QpdLU1zJLr&index=37&t=481s
*/
void ofApp::setup() {
    ofSetWindowTitle("AVAS");
    ofSoundStreamSetup(kDefaultOutputStreams, kDefaultInputStreams);

	imgui_.setup();
    gui_drawer_.setup();
    main_menu_bar_.setup(gui_drawer_, playback_engine_);
    visualizer_.setup();

    volume = 0;
    //sound_loader_.AddSound("metronome_sound", R"(C:\Users\heste\source\repos\CS126FA19\fantastic-finale-kenetec\resources\metronome\Metronome.wav)");
    //sound_loader_.GetSoundPlayer("metronome_sound");

    sound_player.loadSound(
        R"(C:\Users\heste\source\repos\CS126FA19\fantastic-finale-kenetec\resources\waves.mp3)");

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

	imgui_.begin();

	main_menu_bar_.draw();
    gui_drawer_.draw();
    //ImGui::ShowDemoWindow();

    imgui_.end();

	//float clearAlpha = 100;
 //   ofSetColor(255, clearAlpha);
 //   ofSetRectMode(OF_RECTMODE_CORNER);
 //   ofFill();
 //   ofDrawRectangle(0, 0, ofGetWidth(),
 //                   ofGetHeight());  // ofBackground doesn't work with alpha, so
 //                                    // draw a transparent rect

 //   ofSetRectMode(OF_RECTMODE_CENTER);
 //   ofSetColor(0);
 //   ofNoFill();
 //   ofPushMatrix();
 //   ofTranslate(ofGetWidth() / 2,
 //               ofGetHeight() / 2);  // Translate to the center of the screen
 //   for (int i = 0; i < 100; i++) {
 //       ofScale(1.1, 1.1);
 //       // Noise is a topic that deserves a section in a book unto itself
 //       // Check out Section 1.6 of "The Nature of Code" for a good explanation
 //       // http://natureofcode.com/book/introduction/
 //       float time = ofGetElapsedTimef();
 //       float timeScale = 0.5;
 //       float noise = ofSignedNoise(time * timeScale) * 20.0;
 //       ofRotate(noise);
 //       ofDrawRectangle(0, 0, 50, 50);
 //   }
 //   ofPopMatrix();


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