#include "Visualizer.h"

Visualizer::Visualizer() {
    for (int i = 0; i < kMaxNumOfParticles; i++) {
        particles_.push_back(Particle());
    }
}

/*
Code derived from:
https://www.youtube.com/watch?v=IiTsE7P-GDs&list=PL4neAtv21WOmrV8z9rSzL20QpdLU1zJLr&index=37&t=481s
*/
void Visualizer::setup() {
    InitializeFFT();
    LoadShaders();
    SetupBars();
    bass_circle_.setup(fft_smoothed_);
    SetupParticles();
}

void Visualizer::SetupBars() {
    int color_lerp_step = 1 / Visualizer::kNumOfBands;
    for (int i = 0; i < Visualizer::kNumOfBands; i++) {
        bar_colors_.push_back(
            start_color_.lerp(end_color_, color_lerp_step * i));

        ofRectangle rect;
        rect.width = ofGetWidth() / kNumOfBands;
        rect.x = (ofGetWidth() / kNumOfBands) * i;
        rect.y = ofGetHeight();

        bars_.push_back(rect);
    }
}

void Visualizer::SetupParticles() {
    double x_factor = ofGetWidth() / kMaxNumOfParticles;
    double y_factor = ofGetHeight() / kMaxNumOfParticles;

    for (int i = 0; i < kMaxNumOfParticles; i++) {
        Particle& particle = particles_.at(i);

        particle.setup(fft_smoothed_,
                       ofColor(ofRandom(255), ofRandom(255), ofRandom(255)),
                       Range(5 + (kParticleFFTRangeDist * i),
                             (kParticleFFTRangeDist * (i + 1))),
                       ofPoint(x_factor * (ofRandom(i) + 1),
                               y_factor * (ofRandom(i) + 1)));
    }
}

void Visualizer::update() {
    UpdateFFT();
    bass_circle_.update();

    for (Particle& particle : particles_) {
        particle.update();
    }
}

void Visualizer::DrawBasic2D() {
    for (int i = 0; i < Visualizer::kNumOfBands; i++) {
        ofSetColor(bar_colors_.at(i));

        ofRectangle& rect = bars_.at(i);
        rect.height = -(fft_smoothed_[i] * 100);

        ofDrawRectangle(rect);
    }
}

/*
code derived from:
https://openframeworks.cc/ofBook/chapters/shaders.html
*/
void Visualizer::draw() {
    shader_.begin();

    // bass circle
    bass_circle_.draw();

    // draw particles
    for (Particle& particle : particles_) {
        particle.draw();
    }

    shader_.end();
}

void Visualizer::InitializeFFT() {
    fft_smoothed_ = new float[Visualizer::kNumOfBands];
    for (int i = 0; i < Visualizer::kNumOfBands; i++) {
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
    float* value = ofSoundGetSpectrum(Visualizer::kNumOfBands);

    for (int i = 0; i < Visualizer::kNumOfBands; i++) {
        fft_smoothed_[i] =
            Util::SmoothDamp(fft_smoothed_[i], value[i], kFFTDampingFactor);
    }
}