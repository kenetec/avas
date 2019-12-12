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
    std::vector<Measure>* measures_;

	const std::string kAllOctavesKey = "_";
    const std::string kAllNotesKey = "+";
    const std::string kSoundMapFileName = "SOUND_MAP.json";
    

   public:
    Instrument();
    Instrument(const std::string& name);
    Instrument(const std::string& name, const std::string& path_to_instrument);
    Instrument(const std::string& name, const std::string& path_to_instrument,
               std::vector<Measure>* measures);

	/*
	Loads sound_map from set path to instrument.
	*/
    void Load();

	// Gets mapped sound from given NoteName and octave.
	ofSoundPlayer* GetSound(const std::string& note_name_str, int octave);

	/*
	Sets instrument path.
	*/
    void SetInstrumentPath(const std::string& path_to_instrument);

	/*
	Sets name of instrument
	*/
	void SetName(const std::string& name);

	/*
	Gets name of instrument
	*/
	std::string& GetName();

	/*
	Gets sound map
	*/
	std::vector<OctaveMap>& GetSoundMap();

	std::string& GetInstrumentPath();

	void SetMeasures(std::vector<Measure>* measures);

   //private:
    void InitializeSoundMap();
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
