#include "Visualizer.h"

Visualizer::Visualizer() { fftSmoothed_ = nullptr; }

/*
Code derived from:
https://www.youtube.com/watch?v=IiTsE7P-GDs&list=PL4neAtv21WOmrV8z9rSzL20QpdLU1zJLr&index=37&t=481s
*/
void Visualizer::setup() {
    InitializeFFT();
    LoadShaders();
}

void Visualizer::update() { UpdateFFT(); }

void Visualizer::DrawBasic2D() {
    ofSetColor(255);
    for (int i = 0; i < kNumOfBands; i++) {
        ofRectangle rect;
        rect.width = ofGetWidth() / kNumOfBands;
        rect.height = -(fftSmoothed_[i] * 100);
        rect.x = (ofGetWidth() / kNumOfBands) * i;
        rect.y = ofGetHeight();

        ofDrawRectangle(rect);
    }
}

/*
code derived from:
https://openframeworks.cc/ofBook/chapters/shaders.html
*/
void Visualizer::draw() {
    shader_.begin();

	int x_offset = 10;  // ofGetWidth() / kNumOfBands;
    int y_pos = ofGetHeight() / 2;
    int x_size = ofGetWidth() / kNumOfBands;

    for (int band_index = 0; band_index < kNumOfBands; band_index += 13) {
        int height = -(fftSmoothed_[band_index] * 100);

        shader_.setUniform1f("time", ofGetElapsedTimef());

        ofPushMatrix();
        { 
			ofDrawBox(glm::vec3(x_offset * band_index, 500, -20), 10, height, 100);
		}
        ofPopMatrix();

        // translate plane into center screen.
        /*float tx = ofGetWidth() / 2;
        float ty = ofGetHeight() / 2;
        ofTranslate(tx, ty);

        // the mouse/touch Y position changes the rotation of the plane.
        float percentY = ofGetPreviousMouseY() / (float)ofGetHeight();
        float rotation = ofMap(percentY, 0, 1, -60, 60, true) + 60;
        ofRotate(rotation, 1, 0, 0);

        plane_.drawWireframe();*/
    }

    shader_.end();
}

void Visualizer::InitializeFFT() {
    fftSmoothed_ = new float[kNumOfBands];
    for (int i = 0; i < kNumOfBands; i++) {
        fftSmoothed_[i] = 0;
    }
}

void Visualizer::LoadShaders() {
    shader_.load(kShaderVertPath, kShaderFragPath);
}

/*
Code derived from:
https://www.youtube.com/watch?v=IiTsE7P-GDs&list=PL4neAtv21WOmrV8z9rSzL20QpdLU1zJLr&index=37&t=481s
*/
void Visualizer::UpdateFFT() {
    float* value = ofSoundGetSpectrum(kNumOfBands);

    for (int i = 0; i < kNumOfBands; i++) {
        fftSmoothed_[i] *= kFFTSmoothFactor;

        if (fftSmoothed_[i] < value[i]) {
            fftSmoothed_[i] = value[i];
        }
    }
}