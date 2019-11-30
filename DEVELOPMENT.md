# Development Process

## Week 1
- Got project set up with openFrameworks.
- Created a basic audio visualizer with help of [youtube tutorial](https://www.youtube.com/watch?v=IiTsE7P-GDs&list=PL4neAtv21WOmrV8z9rSzL20QpdLU1zJLr&index=37&t=481s).
	- Helped in understanding FFT
- Attempted to implement CMake but horribly failed (will try again another time).
- Added ofxImGui for most robust GUI system.
- Began writing system for music composition.

# Week 2
### 11/25/19
- Created Visualizer class and refactored code.
- Got testing to work with Catch2.
### 11/26/19
- Extensively combed through imgui.h to get an idea of how API works (there is no dedicated documentation -_-).
- Organized files into folders.
- Add more functionality to music structures

# Week 3
### 11/27/19
- Create basic piano roll interface.
- Started gui integration with music structure.
### 11/28/19
- Add some refinements to piano roll.
- Created main menu bar.
- Created GuiDrawer to streamline window drawing.
### 11/29/19
- Squash bugs.
- Rewrote PianoRoll to scale dynamically.
### 11/30/19
- Composer returns all measures.
- "Play" menu item in MainMenuBar.
- Added overloading functions to GuiDrawer.