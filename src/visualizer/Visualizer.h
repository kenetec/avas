#pragma once
#include <math.h>
#include <ofMain.h>

#include "BassCircle.h"
#include "Particle.h"
#include "Util.h"

using ParticlePointer = std::shared_ptr<Particle*>;

class Visualizer {
   private:
    const std::string kShaderVertPath =
        R"(C:\Users\heste\source\repos\CS126FA19\fantastic-finale-kenetec\src\shaders\test_shader\test_shader.vert)";
    const std::string kShaderFragPath =
        R"(C:\Users\heste\source\repos\CS126FA19\fantastic-finale-kenetec\src\shaders\test_shader\test_shader.frag)";
    /*
    Code derived from:
    https://www.youtube.com/watch?v=IiTsE7P-GDs&list=PL4neAtv21WOmrV8z9rSzL20QpdLU1zJLr&index=37&t=481s
    */
    float* fft_smoothed_ = nullptr;
    const float kFFTDampingFactor = 0.9f;

    ofShader shader_;
    ofFbo scene_;
    ofVboMesh mesh_;

    //std::vector<std::shared_ptr<ofRectangle>> bars_;
    std::vector<ofColor> bar_colors_;
    std::vector<ofRectangle> bars_;

    BassCircle bass_circle_;
    std::vector<Particle> particles_;
    const int kMaxNumOfParticles = 10;
    const int kParticleFFTRangeDist = 20;

    ofColor start_color_ = ofColor(138, 249, 255);
    ofColor end_color_ = ofColor(240, 140, 255);

   public:
    static const int kNumOfBands = 512;

    Visualizer();
    void setup();
    void update();
    void draw();
    void DrawBasic2D();

   private:
    // setup
    void InitializeFFT();
    void LoadShaders();
    void SetupParticles();
    void SetupBars();
    // update
    void UpdateFFT();
    void UpdateBassRadius();
    // draw
};