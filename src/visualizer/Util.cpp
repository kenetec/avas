#include "Util.h"

double Util::GetAverageBandValue(float* fft_smoothed, int a, int b) {
    int min_bound = min(a, b);
    int max_bound = max(a, b);

    double avg = 0;
    for (int band_index = min_bound; band_index < max_bound; band_index++) {
        avg += fft_smoothed[band_index];
    }
    avg /= (max_bound - min_bound);
    return avg;
}

double Util::GetAverageBandValue(float* fft_smoothed, const Range& range) {
    return GetAverageBandValue(fft_smoothed, range.low, range.high);
}

int Util::GetAverageBandValueFloored(float* fft_smoothed, int a, int b) {
    return floor(GetAverageBandValue(fft_smoothed, a, b));
}

int Util::GetAverageBandValueFloored(float* fft_smoothed, const Range& range) {
    return floor(GetAverageBandValue(fft_smoothed, range.low, range.high));
}

double Util::GetSignificantBandsAverage(float* fft_smoothed, int a, int b,
                                              double ignore_factor) {
    int min_bound = min(a, b);
    int max_bound = max(a, b);

    double avg = 0;
    int nums_counted = 0;
    double highest_val = -1;
    double ignore_threshold = -1;

    for (int band_index = min_bound; band_index < max_bound; band_index++) {
        double val = fft_smoothed[band_index];

        if (val > highest_val) {
            highest_val = val;
            ignore_threshold = highest_val * ignore_factor;
        }

        if (val > ignore_threshold) {
            avg += fft_smoothed[band_index];
            nums_counted++;
        }
    }
    avg /= nums_counted;
    return avg;
}

double Util::GetSignificantBandsAverage(float* fft_smoothed, const Range& range,
                                              double ignore_factor) {
    return GetSignificantBandsAverage(fft_smoothed, range.low, range.high,
                                      ignore_factor);
}
int Util::GetSignificantBandsAverageFloored(float* fft_smoothed, int a, int b,
                                                  double ignore_factor) {
    return floor(GetSignificantBandsAverage(fft_smoothed, a, b, ignore_factor));
}

int Util::GetSignificantBandsAverageFloored(
    float* fft_smoothed, const Range& range,
                                                  double ignore_factor) {
    return floor(GetSignificantBandsAverage(fft_smoothed, range.low, range.high,
                                            ignore_factor));
}

double Util::GetAverageOfBandValuesOverThreshold(float* fft_smoothed, int a,
                                                  int b,
                                                        double threshold) {
    int min_bound = min(a, b);
    int max_bound = max(a, b);

    double avg = 0;
    int nums_counted = 0;
    for (int band_index = min_bound; band_index < max_bound; band_index++) {
        double val = fft_smoothed[band_index];

        if (val > threshold) {
            avg += fft_smoothed[band_index];
            nums_counted++;
        }
    }
    avg /= nums_counted;
    return avg;
}

double Util::GetAverageOfBandValuesOverThreshold(
    float* fft_smoothed, const Range& range,
                                                        double threshold) {
    return GetAverageOfBandValuesOverThreshold(fft_smoothed, range.low,
                                                range.high,
                                                threshold);
}

int Util::GetAverageOfBandValuesOverThresholdFloored(float* fft_smoothed, int a,
                                                      int b,
                                                            double threshold) {
    return floor(
        GetAverageOfBandValuesOverThreshold(fft_smoothed, a, b, threshold));
}

int Util::GetAverageOfBandValuesOverThresholdFloored(
    float* fft_smoothed, const Range& range,
                                                            double threshold) {
    return floor(GetAverageOfBandValuesOverThreshold(fft_smoothed, range,
                                                      threshold));
}

/*
Code derived from:
https://www.youtube.com/watch?v=IiTsE7P-GDs&list=PL4neAtv21WOmrV8z9rSzL20QpdLU1zJLr&index=37&t=481s
*/
double Util::SmoothDamp(double from, double to, double factor) {
    double damped = from * factor;
    if (damped < to) {
        return to;
    }
    return damped;
}