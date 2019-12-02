#pragma once

#include <string>
#include <map>
#include "ofMain.h"

class SoundLoader {
   public:
    SoundLoader();

	/*
       Creates a SoundPlayer and then returns it.
    */
    ofSoundPlayer* AddSound(std::string file_path);

	/*
		Returns cached SoundPlayer or creates a new one and returns it.
	*/
    ofSoundPlayer* GetSoundPlayer(std::string file_path);

	/*
		Deletes entry in cache.
	*/
    void DeleteSound(std::string file_path);

	std::map<std::string, ofSoundPlayer>& GetPathsToSoundPlayers();

   private:
    std::map<std::string, ofSoundPlayer> paths_to_sound_players;
};
