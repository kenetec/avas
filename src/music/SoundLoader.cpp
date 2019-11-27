#include "SoundLoader.h"

SoundLoader::SoundLoader() {}

void SoundLoader::AddSound(std::string sound_name, std::string file_path) {
    names_to_paths.insert(
            std::pair<std::string, std::string>(sound_name, file_path));
}

ofSoundPlayer* SoundLoader::GetSoundPlayer(std::string sound_name,
                                           std::string file_path) {
    if (names_to_sound_players.find(sound_name) != names_to_sound_players.cend()) {
        return names_to_sound_players.at(sound_name);
    } else {
        ofSoundPlayer* sound_player = new ofSoundPlayer();
        sound_player->setMultiPlay(true);
        sound_player->loadSound(file_path);

        names_to_sound_players.insert(
            std::pair<std::string, ofSoundPlayer*>(sound_name, sound_player));

		AddSound(file_path, sound_name);

        return sound_player;
    }
}

ofSoundPlayer* SoundLoader::GetSoundPlayer(std::string sound_name) {
    return GetSoundPlayer(sound_name, names_to_paths.at(sound_name));
}

void SoundLoader::DeleteSound(std::string sound_name) {
    names_to_sound_players.erase(sound_name);
}