#pragma once

class ReactiveObject {
   protected:
    float* fft_smoothed_ = nullptr;

   public:
    virtual void setup(float* fft_smoothed) { fft_smoothed_ = fft_smoothed; }
    virtual void update(){};
    virtual void draw(){};
};