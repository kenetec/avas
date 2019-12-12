#include "Instrument.h"

Instrument::Instrument() : Instrument("", "", nullptr) {}

Instrument::Instrument(const std::string& name)
    : Instrument(name, "", nullptr) {}

Instrument::Instrument(const std::string& name,
                       const std::string& path_to_instrument)
    : Instrument(name, path_to_instrument, nullptr) {}

Instrument::Instrument(const std::string& name,
                       const std::string& path_to_instrument,
                       std::vector<Measure>* measures) {
    InitializeSoundMap();
    measures_ = measures;
    root_path_ = path_to_instrument;
}

void Instrument::InitializeSoundMap() {
    for (int octave = 0; octave < Instrument::kMaxOctaves; octave++) {
        OctaveMap octave_map;

        for (int note_index = 0; note_index < Instrument::kNotesPerOctaves;
             note_index++) {
            octave_map.insert(std::pair<std::string, ofSoundPlayer*>(
                kNoteNames.at(note_index), nullptr));
        }

        sound_map_.push_back(octave_map);
    }
}

void Instrument::Load() { LoadSoundMapFile(); }

ofSoundPlayer* Instrument::GetSound(const std::string& note_name_str, int octave) {
    if (!sound_map_.empty()) {
        if (std::find(kNoteNames.cbegin(), kNoteNames.cend(), note_name_str) !=
            kNoteNames.cend()) {
            return sound_map_.at(octave).at(note_name_str);
        } else {
            stringstream ss;
            ss << "Note name: \"" << note_name_str << "\" does not exist!";

            throw exception(ss.str().c_str());
		}
    }
    return nullptr;
}

void Instrument::SetInstrumentPath(const std::string& path) {
    root_path_ = path;
}

    std::vector<OctaveMap>& Instrument::GetSoundMap() {
    return sound_map_;
}

void Instrument::SetName(const std::string& name) { name_ = name; }
std::string& Instrument::GetName() { return name_; }

std::string& Instrument::GetInstrumentPath() { return root_path_; }

void Instrument::SetMeasures(std::vector<Measure>* measures) {
    measures_ = measures;
}

/*
code derived from:
https://forum.openframeworks.cc/t/an-example-for-how-to-parse-a-json-file/32420
*/
void Instrument::LoadSoundMapFile() {
    std::string path = ResolvePath(kSoundMapFileName);
    ofFile file(path);

    if (file.exists()) {
        ofJson json = ofLoadJson(path);

        // verify json
        if (SoundMapFileIsValid(json)) {
            LoadSoundMapIntoObject(json);
        }
    }
}

bool Instrument::SoundMapFileIsValid(const ofJson& json_obj) {
    using json = nlohmann::json;

    for (auto it = json_obj.cbegin(); it != json_obj.cend(); ++it) {
        std::string it_key = it.key();

        if (it_key != kAllOctavesKey && it_key != kAllNotesKey) {
            if (it_key.size() != 1 || !isdigit(it_key.c_str()[0])) {
                return false;
            }
        }

        if (!it.value().is_structured()) {
            return false;
        }

        for (auto sub_it = it->cbegin(); sub_it != it->cend(); ++sub_it) {
            if (std::find(kNoteNames.cbegin(), kNoteNames.cend(),
                          sub_it.key()) == kNoteNames.cend()) {
                return false;
            }

            if (!sub_it.value().is_string()) {
                return false;
            }
        }
    }

    return true;
}

void Instrument::LoadSoundMapIntoObject(const ofJson& json_obj) {
    for (auto it = json_obj.cbegin(); it != json_obj.cend(); ++it) {
        std::string it_key = it.key();

        if (it_key == kAllNotesKey) {
            SetAllNotesToSound(it.value());
        } else if (it_key == kAllOctavesKey) {
            SetNotesInAllOctavesToMapping(it.value());
        } else {
            int octave = (int)(it_key.c_str()[0]);
            SetNotesInOctaveToMapping(octave, it.value());
        }
    }
}

void Instrument::SetNotesInOctaveToMapping(int octave, const ofJson& json_obj) {
    OctaveMap* octave_map = &sound_map_.at(octave);

    for (auto it = json_obj.cbegin(); it != json_obj.cend(); ++it) {
        ofSoundPlayer** sound_player = &octave_map->at(it.key());
        std::string path = ResolvePath(it.value());

        if (*sound_player == nullptr) {
            *sound_player = sound_loader_.GetSoundPlayer(path);
        } else {
            (*sound_player)->unloadSound();
            (*sound_player)->loadSound(path);
        }
    }
}

void Instrument::SetNotesInAllOctavesToMapping(const ofJson& json_obj) {
    for (int octave = 0; octave < sound_map_.size(); octave++) {
        SetNotesInOctaveToMapping(octave, json_obj);
    }
}

void Instrument::SetAllNotesToSound(
    const std::string& relative_sound_file_path) {
    for (int octave = 0; octave < sound_map_.size(); octave++) {
        OctaveMap* octave_sound_map = &sound_map_.at(octave);

        for (auto it = octave_sound_map->begin(); it != octave_sound_map->end();
             it++) {
            std::string path = ResolvePath(relative_sound_file_path);

            if (it->second == nullptr) {
                it->second = sound_loader_.GetSoundPlayer(path);
            } else {
                it->second->unloadSound();
                it->second->loadSound(path);
            }
        }
    }
}

std::string Instrument::ResolvePath(const std::string& relative_path) {
    return root_path_ + "/" + relative_path;
}