#pragma once

#include <thread>
#include "Score.h"
#include "SoundLoader.h"

enum class PlaybackEngineState {
	PLAYING,
	STOPPED,
	PAUSED
};

class PlaybackEngine {
   private:
    PlaybackEngineState state_;
    Score score_;
    SoundLoader* sound_loader_;

   public:
    PlaybackEngine(){};
    PlaybackEngine(SoundLoader& sound_loader);

	void Load(Score& score){};
    void Load(std::vector<std::vector<Measure>>& measures);

	void Play(std::vector<std::vector<Measure>>& all_measures);
    void PlayBeatAtSubdivisionAsync(Beat& beat);
    void Stop();
    void Pause();

    PlaybackEngineState GetState() { return state_; };
};
