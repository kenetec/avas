#include "SoundLoader.h"

SoundLoader::SoundLoader() {}

ofSoundPlayer* SoundLoader::AddSound(std::string file_path) {
    if (file_path.empty()) return nullptr;

    ofSoundPlayer sound_player;
    sound_player.setMultiPlay(true);
    sound_player.loadSound(file_path);

    paths_to_sound_players.insert(
        std::pair<std::string, ofSoundPlayer>(file_path, sound_player));

    return &paths_to_sound_players.at(file_path);
}

ofSoundPlayer* SoundLoader::GetSoundPlayer(std::string file_path) {
    if (paths_to_sound_players.find(file_path) !=
        paths_to_sound_players.cend()) {
        return &paths_to_sound_players.at(file_path);
    }

    return AddSound(file_path);
}

void SoundLoader::DeleteSound(std::string file_path) {
    paths_to_sound_players.erase(file_path);
}

std::map<std::string, ofSoundPlayer>& SoundLoader::GetPathsToSoundPlayers() {
    return paths_to_sound_players;
}