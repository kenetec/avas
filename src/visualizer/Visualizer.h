#pragma once
#include <math.h>
#include <ofMain.h>
#include "TailCircle.h"


struct Range {
    int low = 0;
    int high = 0;
    int dist = 0;
    Range(int l, int h) : low(l), high(h), dist(h - l){};
};

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
    const int kNumOfBands = 512;

    const Range kBassFFTRange = Range(0, 5);
    const int kBassRadiusFactor = 60;
    const double kBassRadiusDampingFactor = 0.9;
    const double kBassFFTIgnoreFraction = 0.5;
    //const double kBassFFTThreshold = 0.2;
    int bass_radius_ = 0;

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
    void UpdateBassRadius();
    // draw

    // helpers

    /*
        Get average band value within a range of a to b (a inclusive, b
       exclusive).
    */
    double GetAverageBandValue(int a, int b);
    double GetAverageBandValue(const Range& range);
    int GetAverageBandValueFloored(int a, int b);
    int GetAverageBandValueFloored(const Range& range);

    /*
        Gets average band value withing range of a to b (a inclusive, b
       exclusive)
       Ignores values under [highest value] * [ignore_factor]
    */
    double GetSignificantBandsAverage(int a, int b, double ignore_factor);
    double GetSignificantBandsAverage(const Range& range, double ignore_factor);
    int GetSignificantBandsAverageFloored(int a, int b, double ignore_factor);
    int GetSignificantBandsAverageFloored(const Range& range,
                                          double ignore_factor);

    /*
        Gets average of band values with range of a to b (a inclusive, b
       exclusive) Ignores values under threshold;
    */
    double GetAverageOfBandValuesUnderThreshold(int a, int b, double threshold);
    double GetAverageOfBandValuesUnderThreshold(const Range& range,
                                                double threshold);
    int GetAverageOfBandValuesUnderThresholdFloored(int a, int b,
                                                    double threshold);
    int GetAverageOfBandValuesUnderThresholdFloored(const Range& range,
                                                    double threshold);

    double SmoothDamp(double from, double to, double factor);
};