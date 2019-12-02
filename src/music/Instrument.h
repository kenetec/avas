#pragma once
#include <algorithm>
#include <vector>
#include <sstream>
#include <ofMain.h>
#include "Measure.h"
#include "SoundLoader.h"

using OctaveMap = std::map<std::string, ofSoundPlayer*>;

class Instrument {
   private:
    std::string name_;
    std::string root_path_;

	/*
		{
			0: {		<- octave
				"C": p_sound_player <- note name to sound player
			} 
		}
	*/
    std::vector<OctaveMap> sound_map_;

    SoundLoader sound_loader_;
    std::vector<Measure> measures_;

	const std::string kAllOctavesKey = "_";
    const std::string kAllNotesKey = "+";
    const std::string kSoundMapFileName = "SOUND_MAP.json";
    

   public:
    Instrument(const std::string& name, const std::string& path_to_instrument);
    void GenerateSoundMap();

	void SetName(const std::string& name);
	std::string& GetName();

	std::vector<OctaveMap>& GetSoundMap();

   //private:
    void LoadSoundMapFile();
    bool SoundMapFileIsValid(const ofJson& json_obj);
    void LoadSoundMapIntoObject(const ofJson& json_obj);
    void SetNotesInOctaveToMapping(int octave, const ofJson& json_obj);
    void SetNotesInAllOctavesToMapping(const ofJson& json_obj);
    void SetAllNotesToSound(const std::string& relative_sound_file_path);

    std::string ResolvePath(const std::string& relative_path);

	static const int kMaxOctaves = 6;
    static const int kNotesPerOctaves = 12;
    const std::vector<std::string> kNoteNames = {
        "C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab", "A", "Bb", "B"};
};
