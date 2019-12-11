#include "Serializer.h"

void Serializer::SaveScore(const std::string& file_path, Score& score) {
    nlohmann::json json;

    json["bpm"] = score.GetBPM();
    json["instrument_scores"] =
        SaveInstrumentScores(score.GetMeasureContainers());

    std::ofstream file(file_path);
    if (file.is_open()) {
        file << json.dump();
    }
}

json Serializer::SaveInstrumentScores(
    std::vector<InstrumentScore>& instrument_scores) {
    json jarray = nlohmann::json::array();

    for (int i = 0; i < instrument_scores.size(); i++) {
        InstrumentScore& instrument_score = instrument_scores.at(i);
        nlohmann::json instrument_score_jobj = nlohmann::json::object();

        instrument_score_jobj["instrument"] =
            instrument_score.instrument->GetInstrumentPath();
        instrument_score_jobj["measures"] =
            SaveMeasures(instrument_score.measures);

        jarray.push_back(instrument_score_jobj);
    }

    return jarray;
}

json Serializer::SaveMeasures(std::vector<Measure>& measures) {
    json jarray = json::array();

    for (int i = 0; i < measures.size(); i++) {
        Measure& measure = measures.at(i);
        json measure_jobj = json::object();

        json time_signature_jobj = json::object();
        time_signature_jobj["n_beats"] =
            measure.time_signature.beats_per_measure;
        time_signature_jobj["note_type"] =
            measure.time_signature.note_type_as_beat;

        measure_jobj["time_signature"] = time_signature_jobj;
        measure_jobj["beats"] = SaveBeats(measure.beats);

        jarray.push_back(measure_jobj);
    }

    return jarray;
}

json Serializer::SaveBeats(std::vector<Beat>& beats) {
    json jarray = json::array();

    for (int i = 0; i < beats.size(); i++) {
        Beat& beat = beats.at(i);
        json beat_obj = json::object();

        beat_obj["notes"] = SaveNotes(beat.GetNotes());

        jarray.push_back(beat_obj);
    }

    return jarray;
}

json Serializer::SaveNotes(std::vector<Note>& notes) {
    json jarray = json::array();

    for (Note& note : notes) {
        json note_jobj = json::object();

        note_jobj["note_name"] = note.note_name_str;
        note_jobj["octave"] = note.octave;
        note_jobj["active"] = note.active;

        jarray.push_back(note_jobj);
    }

    return jarray;
}