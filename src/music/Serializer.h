#pragma once

#include <json.hpp>
#include "Score.h"

using namespace nlohmann;

class Serializer {
   public:
    /*
    {
    "bpm": 120,
    "instrument_scores": [...]
    }*/
    static void SaveScore(const std::string& file_path, Score& score);

   private:
    /*
    [
        {"instrument": {"name": string, "path": string}, "measures": [...]}
        ...
    ]
    */
    static json SaveInstrumentScores(std::vector<InstrumentScore>& instrument_score);
    /*
    [
        {
            "time_signature": {
                "n_beats": number,
                "note_type": NoteType
            }
            "beats": [...]
    ]
    */
    static json SaveMeasures(std::vector<Measure>& measures);

    /*
    [
        {"notes": [...]}
    ]
    */
    static json SaveBeats(std::vector<Beat>& beats);

    /*
    [
        {"note_name": "C", "octave": 0, "active": true},
        ...
    ]
    */
    static json SaveNotes(std::vector<Note>& notes);
};
