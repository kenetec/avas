#pragma once

#include <string>
#include <map>
#include "ofMain.h"

class SoundLoader {
   public:
    SoundLoader();

	/*
		Adds sound_name to map of sound_name->file_path
	*/
    void AddSound(std::string file_path, std::string sound_name);

	/*
       Returns cached SoundPlayer or automatically creates a SoundPlayer if none exists, caches, and then returns it.
    */
	ofSoundPlayer* GetSoundPlayer(std::string file_path,
                                  std::string sound_name);

	/*
		Returns cached SoundPlayer or automatically creates a SoundPlayer if none exists, caches, and then returns it.
	*/
    ofSoundPlayer* GetSoundPlayer(std::string sound_name);

	/*
		Deletes entry in cache.
	*/
    void DeleteSound(std::string sound_name);

   private:
    std::map<std::string, std::string> names_to_paths;
    std::map<std::string, ofSoundPlayer> sound_players;
};
