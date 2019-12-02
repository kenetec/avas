#pragma once
#include <vector>
#include <string>

enum class NoteType {
    SIXTEENTH,
    EIGHTH,
    QUARTER,
    HALF,
    WHOLE,
};

enum class NoteName { C, Db, D, Eb, E, F, Gb, G, Ab, A, Bb, B };

struct Note {
    NoteType note_type;
    NoteName note_name;
    std::string note_name_str;
    int octave;
    bool active = false;
};
