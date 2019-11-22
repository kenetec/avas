#pragma once

#include <string>
#include <map>
#include "ofMain.h"

class SoundLoader {
   public:
    SoundLoader();
    void AddSound(std::string file_path, std::string sound_name);
    void LoadSound(std::string sound_name);
    ofSoundPlayer* GetSoundPlayer(std::string sound_name);
    void DeleteSound(std::string sound_name);

   private:
    std::map<std::string, ofSoundPlayer> sound_players;
};
