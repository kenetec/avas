#pragma once

#include <thread>
#include <math.h>
#include "Score.h"
#include "SoundLoader.h"
#include "InstrumentScorePlayer.h"

enum class PlaybackEngineState { PLAYING, STOPPED, PAUSED };

class PlaybackEngine {
   private:
    PlaybackEngineState state_;
    Score score_;
    SoundLoader* sound_loader_ = nullptr;
    double ms_between_beats_ = 0;
    std::vector<std::shared_ptr<InstrumentScorePlayer>> instrument_score_players_;

   public:
    PlaybackEngine(){};
    ~PlaybackEngine();

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