#pragma once

#include <ofMain.h>
#include "Util.h"
#include "ReactiveObject.h"

class BassCircle : public ReactiveObject {
   private:
    const Range fft_range_ = Range(0, 5);
    const int radius_factor_ = 200;
    const double radius_damping_factor_ = 0.9;
    const double fft_ignore_fraction_ = 0.5;
    int radius_ = 0;
   public:
    void update() override;
    void draw() override;
};
