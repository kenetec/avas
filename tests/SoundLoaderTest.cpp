#include "../src/music/SoundLoader.h"
#include "catch.hpp"

namespace SoundLoaderTest {
std::string kFilePath =
    R"(C:\Users\heste\source\repos\CS126FA19\fantastic-finale-kenetec\resources\waves.mp3)";

TEST_CASE("AddSound") {
    SoundLoader sound_loader;
    sound_loader.AddSound(kFilePath);

    std::map<std::string, ofSoundPlayer> paths_to_sounds =
        sound_loader.GetPathsToSoundPlayers();

    REQUIRE(paths_to_sounds.find(kFilePath) != paths_to_sounds.cend());
}

TEST_CASE("DeleteSound") {
    SoundLoader sound_loader;
    sound_loader.AddSound(kFilePath);

    ofSoundPlayer *sound_player = sound_loader.GetSoundPlayer(kFilePath);
    sound_loader.DeleteSound(kFilePath);

    std::map<std::string, ofSoundPlayer> paths_to_sounds =
        sound_loader.GetPathsToSoundPlayers();

    REQUIRE(paths_to_sounds.find(kFilePath) == paths_to_sounds.cend());
}

TEST_CASE("GetSoundPlayer from empty file path") {
    SoundLoader sound_loader;
    ofSoundPlayer *sound_player = sound_loader.GetSoundPlayer("");

    REQUIRE(sound_player == nullptr);
}

TEST_CASE("GetSoundPlayer from file path") {
    SoundLoader sound_loader;
    sound_loader.AddSound(kFilePath);

    ofSoundPlayer *sound_player =
        sound_loader.GetSoundPlayer(kFilePath);

    REQUIRE(sound_player != nullptr);
    REQUIRE(sound_player->isLoaded());
};
}  // namespace SoundLoaderTest