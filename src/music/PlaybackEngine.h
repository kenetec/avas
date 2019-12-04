#pragma once

#include <thread>
#include <math.h>
#include "Score.h"
#include "SoundLoader.h"
#include "MeasurePlayer.h"

enum class PlaybackEngineState { PLAYING, STOPPED, PAUSED };

class PlaybackEngine {
   private:
    PlaybackEngineState state_;
    Score score_;
    SoundLoader* sound_loader_;
    double ms_between_beats_ = 0;
	MeasurePlayer measure_player;

   public:
    PlaybackEngine(){};

    void Load(Score& score){};
    void Load(std::vector<std::vector<Measure>>& measures);

    void Play(Score& score);
    void PlayBeatAtSubdivisionAsync(Beat& beat);
    void Stop();
    void Pause();

    PlaybackEngineState GetState() { return state_; };

   private:
    void CalculateTimeBetweenBeats();
};