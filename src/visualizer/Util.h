#pragma once

#include <ofMain.h>

struct Range {
    int low = 0;
    int high = 0;
    int dist = 0;
    Range(){};
    Range(int l, int h) : low(l), high(h), dist(h - l){};
};


class Util {
   public:
    /*
            Get average band value within a range of a to b (a inclusive, b
           exclusive).
        */
    static double GetAverageBandValue(float* fft_smoothed, int a, int b);
    static double GetAverageBandValue(float* fft_smoothed, const Range& range);
    static int GetAverageBandValueFloored(float* fft_smoothed, int a, int b);
    static int GetAverageBandValueFloored(
        float* fft_smoothed, const Range& range);

    /*
        Gets average band value withing range of a to b (a inclusive, b
       exclusive)
       Ignores values under [highest value] * [ignore_factor]
    */
    static double GetSignificantBandsAverage(float* fft_smoothed, int a, int b,
                                             double ignore_factor);
    static double GetSignificantBandsAverage(
        float* fft_smoothed, const Range& range,
                                            double ignore_factor);
    static int GetSignificantBandsAverageFloored(float* fft_smoothed, int a,
                                                 int b,
                                                double ignore_factor);
    static int GetSignificantBandsAverageFloored(
        float* fft_smoothed, const Range& range,
                                          double ignore_factor);

    /*
        Gets average of band values with range of a to b (a inclusive, b
       exclusive) Ignores values under threshold;
    */
    static double GetAverageOfBandValuesOverThreshold(float* fft_smoothed, int a,
                                                       int b,
                                                      double threshold);
    static double GetAverageOfBandValuesOverThreshold(
        float* fft_smoothed, const Range& range,
                                                double threshold);
    static int GetAverageOfBandValuesOverThresholdFloored(
        float* fft_smoothed, int a, int b,
                                                    double threshold);
    static int GetAverageOfBandValuesOverThresholdFloored(
        float* fft_smoothed, const Range& range,
                                                    double threshold);

    /*
    Gets highest FFT values within a given range and averages them.
    */
    static double GetPulse(){};

    static double SmoothDamp(double from, double to,
                             double factor);
};
