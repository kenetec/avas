#pragma once
#include <ofMain.h>

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
    float *fftSmoothed_;
    const float kFFTSmoothFactor = 0.9f;
    const int kNumOfBands = 128;

    ofShader shader_;
    ofFbo scene_;
    ofVboMesh mesh_;
   public:
    Visualizer();
    void setup();
    void update();
    void draw();
    void DrawBasic2D();

   private:
	// setup
    void InitializeFFT();
    void LoadShaders();
	// update
	void UpdateFFT();
	// draw
};