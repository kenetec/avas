#include "SoundLoader.h"

SoundLoader::SoundLoader() {}

void SoundLoader::AddSound(std::string file_path, std::string sound_name) {
    if (names_to_paths.find(sound_name) == names_to_paths.cend()) {
        names_to_paths.insert(
            std::pair<std::string, std::string>(file_path, sound_name));
    } else {
        throw "sound_name \"" + sound_name + "\" already exists in map!";
	}
}

ofSoundPlayer* SoundLoader::GetSoundPlayer(std::string file_path, std::string sound_name) {
    if (sound_players.find(sound_name) != sound_players.cend()) {
        return &sound_players.at(sound_name);
    } else {
        ofSoundPlayer sound_player;
        sound_player.loadSound(file_path);

        sound_players.insert(
            std::pair<std::string, ofSoundPlayer>(sound_name, sound_player));

        return &sound_player;
    }
}

ofSoundPlayer* SoundLoader::GetSoundPlayer(std::string sound_name) {
    return GetSoundPlayer(names_to_paths.at(sound_name), sound_name);
}

void SoundLoader::DeleteSound(std::string sound_name) {
    sound_players.erase(sound_name);
}