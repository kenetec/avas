#include "Deserializer.h"

Score Deserializer::LoadScore(const std::string& file_path) {
    Score score;

    std::ifstream file(file_path);
    if (file.is_open()) {
        json score_json;
        file >> score_json;

        std::vector<InstrumentScore> instrument_scores =
            LoadInstrumentScores(score_json.at("instrument_scores"));

        score.SetBPM(score_json.at("bpm").get<int>());
        // set score instrument scores
        score.SetInstrumentScores(instrument_scores);
    }

    return score;
}

std::vector<InstrumentScore> Deserializer::LoadInstrumentScores(
    json instrument_scores_array) {
    std::vector<InstrumentScore> instrument_scores;

    for (json instrument_score_json : instrument_scores_array) {
        json instrument_json = instrument_score_json.at("instrument");
        std::string instrument_name =
            instrument_json.at("name").get<std::string>();
        std::string instrument_path =
            instrument_json.at("path").get<std::string>();

        InstrumentScore instrument_score;

        instrument_score.instrument =
            new Instrument(instrument_name, instrument_path);
        instrument_score.measures =
            LoadMeasures(instrument_score_json.at("measures"));

        instrument_scores.push_back(instrument_score);
    }

    return instrument_scores;
}

std::vector<Measure> Deserializer::LoadMeasures(json measures_array) {
    std::vector<Measure> measures;

    for (json measure_jobj : measures_array) {
        json time_signature_json = measure_jobj.at("time_signature");
        TimeSignature time_signature;
        time_signature.beats_per_measure =
            time_signature_json.at("n_beats").get<int>();
        time_signature.note_type_as_beat =
            time_signature_json.at("note_type").get<NoteType>();

        Measure measure;
        measure.time_signature = time_signature;

        measure.beats = LoadBeats(measure_jobj.at("beats"));

        measures.push_back(measure);
    }

    return measures;
}

std::vector<Beat> Deserializer::LoadBeats(json beats_array) {
    std::vector<Beat> beats;

    for (json beat_jobj : beats_array) {
        Beat beat;
        // set beat notes
        beat.SetNotes(LoadNotes(beat_jobj.at("notes")));

        beats.push_back(beat);
    }

    return beats;
}

std::vector<Note> Deserializer::LoadNotes(json notes_array) {
    std::vector<Note> notes;
    for (json note_jobj : notes_array) {
        Note note;
        note.active = note_jobj.at("active").get<bool>();
        note.note_name_str = note_jobj.at("note_name").get<std::string>();
        note.octave = note_jobj.at("octave").get<int>();

        notes.push_back(note);
    }

    return notes;
}