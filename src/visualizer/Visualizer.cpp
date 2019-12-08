#include "Visualizer.h"

Visualizer::Visualizer() { fft_smoothed_ = nullptr; }

/*
Code derived from:
https://www.youtube.com/watch?v=IiTsE7P-GDs&list=PL4neAtv21WOmrV8z9rSzL20QpdLU1zJLr&index=37&t=481s
*/
void Visualizer::setup() {
    InitializeFFT();
    LoadShaders();
}

void Visualizer::update() {
    UpdateFFT();
    UpdateBassRadius();
}

// find impluse
void Visualizer::UpdateBassRadius() {
    bass_radius_ = SmoothDamp(bass_radius_,
                              GetSignificantBandsAverageFloored(
                                  kBassFFTRange, kBassFFTIgnoreFraction) *
                                  kBassRadiusFactor,
                              kBassRadiusDampingFactor);
}

void Visualizer::DrawBasic2D() {
    ofColor start_color =
        ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
    ofColor end_color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));

    ofColor current_color(255);

    for (int i = 0; i < kNumOfBands; i++) {
        int group = i % 10;
        if (i % 10 == 0) {
            current_color =
                ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
            ofSetColor(current_color);
        }

        /*double lerp_amount = i / kNumOfBands;
        ofSetColor(ofColor(ofLerp(start_color.r, end_color.r, lerp_amount),
                           ofLerp(start_color.g, end_color.g, lerp_amount),
                           ofLerp(start_color.b, end_color.b, lerp_amount)));*/

        ofRectangle rect;
        rect.width = ofGetWidth() / kNumOfBands;
        rect.height = -(fft_smoothed_[i] * 100);
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

    int window_width = ofGetWidth();
    int window_height = ofGetHeight();

    // bass circle
    ofSetColor(255);
    ofCircle(window_width / 2, window_height / 2, bass_radius_);

    // draw tails

    /*for (int band_index = 0; band_index < kNumOfBands; band_index += 13) {
        int height = -(fftSmoothed_[band_index] * 100);

        shader_.setUniform1f("time", ofGetElapsedTimef());

        ofPushMatrix();
        {
            ofDrawBox(glm::vec3(x_offset * band_index, 500, -20), 10,
    height, 100);
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

        plane_.drawWireframe();
    }*/

    shader_.end();
}

void Visualizer::InitializeFFT() {
    fft_smoothed_ = new float[kNumOfBands];
    for (int i = 0; i < kNumOfBands; i++) {
        fft_smoothed_[i] = 0;
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
        fft_smoothed_[i] =
            SmoothDamp(fft_smoothed_[i], value[i], kFFTDampingFactor);
    }
}

double Visualizer::GetAverageBandValue(int a, int b) {
    int min_bound = min(a, b);
    int max_bound = max(a, b);

    double avg = 0;
    for (int band_index = min_bound; band_index < max_bound; band_index++) {
        avg += fft_smoothed_[band_index];
    }
    avg /= (max_bound - min_bound);
    return avg;
}

double Visualizer::GetAverageBandValue(const Range& range) {
    return GetAverageBandValue(range.low, range.high);
}

int Visualizer::GetAverageBandValueFloored(int a, int b) {
    return floor(GetAverageBandValue(a, b));
}

int Visualizer::GetAverageBandValueFloored(const Range& range) {
    return floor(GetAverageBandValue(range.low, range.high));
}

double Visualizer::GetSignificantBandsAverage(int a, int b,
                                              double ignore_factor) {
    int min_bound = min(a, b);
    int max_bound = max(a, b);

    double avg = 0;
    int nums_counted = 0;
    double highest_val = -1;
    double ignore_threshold = -1;

    for (int band_index = min_bound; band_index < max_bound; band_index++) {
        double val = fft_smoothed_[band_index];

        if (val > highest_val) {
            highest_val = val;
            ignore_threshold = highest_val * ignore_factor;
        }

        if (val > ignore_threshold) {
            avg += fft_smoothed_[band_index];
            nums_counted++;
        }
    }
    avg /= nums_counted;
    return avg;
}

double Visualizer::GetSignificantBandsAverage(const Range& range,
                                              double ignore_factor) {
    return GetSignificantBandsAverage(range.low, range.high, ignore_factor);
}
int Visualizer::GetSignificantBandsAverageFloored(int a, int b,
                                                  double ignore_factor) {
    return floor(GetSignificantBandsAverage(a, b, ignore_factor));
}

int Visualizer::GetSignificantBandsAverageFloored(const Range& range,
                                                  double ignore_factor) {
    return floor(
        GetSignificantBandsAverage(range.low, range.high, ignore_factor));
}

double Visualizer::GetAverageOfBandValuesUnderThreshold(int a, int b,
                                                        double threshold) {
    int min_bound = min(a, b);
    int max_bound = max(a, b);

    double avg = 0;
    int nums_counted = 0;
    for (int band_index = min_bound; band_index < max_bound; band_index++) {
        double val = fft_smoothed_[band_index];

        if (val > threshold) {
            avg += fft_smoothed_[band_index];
            nums_counted++;
        }
    }
    avg /= nums_counted;
    return avg;
}

double Visualizer::GetAverageOfBandValuesUnderThreshold(const Range& range,
                                                        double threshold) {
    return GetAverageOfBandValuesUnderThreshold(range.low, range.high,
                                                threshold);
}

int Visualizer::GetAverageOfBandValuesUnderThresholdFloored(int a, int b,
                                                            double threshold) {
    return floor(GetAverageOfBandValuesUnderThreshold(a, b, threshold));
}

int Visualizer::GetAverageOfBandValuesUnderThresholdFloored(const Range& range,
                                                            double threshold) {
    return floor(GetAverageOfBandValuesUnderThreshold(range, threshold));
}

/*
Code derived from:
https://www.youtube.com/watch?v=IiTsE7P-GDs&list=PL4neAtv21WOmrV8z9rSzL20QpdLU1zJLr&index=37&t=481s
*/ 
double Visualizer::SmoothDamp(double from, double to, double factor) {
    double damped = from * factor;
    if (damped < to) {
        return to;
    }
    return damped;
}