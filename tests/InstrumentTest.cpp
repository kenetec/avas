#include "catch.hpp"
#include "music/Instrument.h"

namespace InstrumentTest {

const std::string kPathToInstrument =
    R"(C:\Users\heste\source\repos\CS126FA19\fantastic-finale-kenetec\test_resources\metronome)";
const std::string kInstrumentName = "Metronome";

TEST_CASE("Prepopulates sound map") {
    Instrument instrument(kInstrumentName, kPathToInstrument);
    std::vector<OctaveMap> sound_map = instrument.GetSoundMap();

    SECTION("Not empty") { REQUIRE_FALSE(sound_map.empty()); }

    SECTION("6 octaves") {
        REQUIRE(sound_map.size() == instrument.kMaxOctaves);
    }

    SECTION("Octave maps are populated") {
        for (int octave = 0; octave < instrument.kMaxOctaves; octave++) {
            OctaveMap octave_map = sound_map.at(octave);
            for (auto it = octave_map.cbegin(); it != octave_map.cend(); it++) {
                REQUIRE(std::find(kNoteNames.cbegin(),
                                  kNoteNames.cend(),
                                  it->first) != kNoteNames.cend());

                REQUIRE(it->second == nullptr);
            }
        }
    }
}

TEST_CASE("Instrument can load json") {
    Instrument instrument(kInstrumentName, kPathToInstrument);

    SECTION("Can verify json") {
        ofJson json = ofLoadJson(kPathToInstrument);
        REQUIRE(instrument.SoundMapFileIsValid(json) == true);
    }
}

TEST_CASE("LoadSoundMapFile") {
    Instrument instrument(kInstrumentName, kPathToInstrument);

    instrument.LoadSoundMapFile();

    std::vector<OctaveMap> sound_map = instrument.GetSoundMap();

    SECTION("Is not empty") { REQUIRE_FALSE(sound_map.empty()); }

    SECTION("Loads sounds") {
        for (int octave_index = 0; octave_index < sound_map.size();
             octave_index++) {
            OctaveMap octave_map = sound_map.at(octave_index);
            
			for (auto it = octave_map.cbegin(); it != octave_map.cend(); it++) {
                REQUIRE(it->second != nullptr);
                REQUIRE(it->second->isLoaded());
            }
        }
    }
}

}  // namespace InstrumentTest