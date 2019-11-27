#include "../src/music/SoundLoader.h"
#include "catch.hpp"

namespace SoundLoaderTest {
std::string kSoundName = "waves";
std::string kFilePath =
    R"(C:\Users\heste\source\repos\CS126FA19\fantastic-finale-kenetec\resources\waves.mp3)";

TEST_CASE("GetSoundPlayer from empty sound name and file path") {
    SoundLoader sound_loader;
    ofSoundPlayer *sound_player = sound_loader.GetSoundPlayer("", "");

    REQUIRE(sound_player != nullptr);
    REQUIRE_FALSE(sound_player->isLoaded());
}

TEST_CASE("GetSoundPlayer from empty file path") {
    SoundLoader sound_loader;
    ofSoundPlayer *sound_player = sound_loader.GetSoundPlayer("waves", "");

    REQUIRE(sound_player != nullptr);
    REQUIRE_FALSE(sound_player->isLoaded());
}

TEST_CASE("GetSoundPlayer from file path") {
    SoundLoader sound_loader;
    ofSoundPlayer *sound_player =
        sound_loader.GetSoundPlayer(kSoundName, kFilePath);

    REQUIRE(sound_player != nullptr);
    REQUIRE(sound_player->isLoaded());
};

TEST_CASE("GetSoundPlayer from sound_name") {
    SoundLoader sound_loader;
    sound_loader.AddSound(kSoundName, kFilePath);

    ofSoundPlayer *sound_player = sound_loader.GetSoundPlayer("waves");

    REQUIRE(sound_player != nullptr);
    REQUIRE(sound_player->isLoaded());
}

TEST_CASE("AddSound") {
    SoundLoader sound_loader;
    sound_loader.AddSound(kSoundName, kFilePath);

	std::map<std::string, std::string> *names_to_path =
        sound_loader.GetNamesToPaths();

	REQUIRE(names_to_path->find(kSoundName) != names_to_path->cend());
}

TEST_CASE("DeleteSound") {
    SoundLoader sound_loader;
    sound_loader.AddSound(kSoundName, kFilePath);

    ofSoundPlayer *sound_player = sound_loader.GetSoundPlayer(kSoundName);
    sound_loader.DeleteSound(kSoundName);

    std::map<std::string, ofSoundPlayer*> *sound_players =
        sound_loader.GetNamesToSoundPlayers();

	std::map<std::string, std::string> *names_to_paths =
        sound_loader.GetNamesToPaths();

    REQUIRE(sound_players->find(kSoundName) == sound_players->cend());
    REQUIRE(names_to_paths->find(kSoundName) != names_to_paths->cend());
}

}  // namespace SoundLoaderTest