#pragma once

#include <string>
#include <map>
#include "ofMain.h"

class SoundLoader {
   public:
    SoundLoader();
    void LoadSound(std::string file_path);
    ofSoundPlayer* GetSoundPlayer(std::string sound_name);

   private:
    std::map<std::string, ofSoundPlayer> sound_players;
};
