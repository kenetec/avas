#pragma once
#include <string>
#include <vector>

enum class NoteType {
    SIXTEENTH,
    EIGHTH,
    QUARTER,
    HALF,
    WHOLE,
};

struct Note {
    //NoteType note_type;
    std::string note_name_str;
    int octave;
    bool active = false;

    Note(std::string note_name_str, int octave) : note_name_str(note_name_str), octave(octave) {};
};
