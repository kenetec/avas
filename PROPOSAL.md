<!-- Write your proposal here! Make sure to use properly-formatted Markdown! -->
# Audio Visualizer and Sound Board

For my final project, I will create an interface for the user to map different sounds to the keyboard
and when a mapped key is pressed, it plays the audio and creates interesting visuals on the screen.
The user will be able to create full length songs with multiple channels mixing and be able save and
replay these runs.


## Motivation
My motivation for this project follows from the fact that I have extensive experience performing
live music. In addition, I have ran into situations in which I want to create a quick idea that is
in my head at a given moment, however, using fully featured DAWS (digital audio workstations), such 
as Ableton and FL Studio, is too cumbersome. This project aims to alleivate that struggle by 
allowing the user to quickly come up with musical ideas.

## External Libraries
- [JSON Library](https://nlohmann.github.io/json/) (using json to save songs/history)
- [audiofile](https://audiofile.68k.org/) (for writing to MP3)

### External Libraries for Stretch Goals
- [kfr](https://www.kfrlib.com/) (for cool filters)
- [bento4](https://www.bento4.com/) (for exporting to MP4)

## Roadmap
- Week 1: Basic sound board and visuals completed
- Week 2: Implement channels, timing/quantization, metronome, keyboard gestures
- Week 3: More fleshed out keyboard interactions / saving and loading
- Week 4: Prettier visuals

## Stretch Goals
- Exporting to MP3/WAV/MP4
- 3D particles
- MIDI support
- External MIDI controller support
- Backlit keyboard visuals (similar to Ableton Push)
- VST plugin support (VERY LONG STRETCH)