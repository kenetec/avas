#pragma once

#include <json.hpp>
#include "Score.h"

using namespace nlohmann;

class Deserializer {
   public:
    static Score LoadScore(const std::string& file_path);

   private:
    static std::vector<InstrumentScore> LoadInstrumentScores(json instrument_scores_array);
    static std::vector<Measure> LoadMeasures(json measures_array);
    static std::vector<Beat> LoadBeats(json beats_array);
    static std::vector<Note> LoadNotes(json notes_array);
};
