# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ruby/Desktop/Quiz-Game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ruby/Desktop/Quiz-Game/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/QuizGame.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/QuizGame.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/QuizGame.dir/flags.make

CMakeFiles/QuizGame.dir/src/AssetMan.cpp.o: CMakeFiles/QuizGame.dir/flags.make
CMakeFiles/QuizGame.dir/src/AssetMan.cpp.o: ../src/AssetMan.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ruby/Desktop/Quiz-Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/QuizGame.dir/src/AssetMan.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QuizGame.dir/src/AssetMan.cpp.o -c /Users/ruby/Desktop/Quiz-Game/src/AssetMan.cpp

CMakeFiles/QuizGame.dir/src/AssetMan.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QuizGame.dir/src/AssetMan.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ruby/Desktop/Quiz-Game/src/AssetMan.cpp > CMakeFiles/QuizGame.dir/src/AssetMan.cpp.i

CMakeFiles/QuizGame.dir/src/AssetMan.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QuizGame.dir/src/AssetMan.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ruby/Desktop/Quiz-Game/src/AssetMan.cpp -o CMakeFiles/QuizGame.dir/src/AssetMan.cpp.s

CMakeFiles/QuizGame.dir/src/Game.cpp.o: CMakeFiles/QuizGame.dir/flags.make
CMakeFiles/QuizGame.dir/src/Game.cpp.o: ../src/Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ruby/Desktop/Quiz-Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/QuizGame.dir/src/Game.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QuizGame.dir/src/Game.cpp.o -c /Users/ruby/Desktop/Quiz-Game/src/Game.cpp

CMakeFiles/QuizGame.dir/src/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QuizGame.dir/src/Game.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ruby/Desktop/Quiz-Game/src/Game.cpp > CMakeFiles/QuizGame.dir/src/Game.cpp.i

CMakeFiles/QuizGame.dir/src/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QuizGame.dir/src/Game.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ruby/Desktop/Quiz-Game/src/Game.cpp -o CMakeFiles/QuizGame.dir/src/Game.cpp.s

CMakeFiles/QuizGame.dir/src/GamePlay.cpp.o: CMakeFiles/QuizGame.dir/flags.make
CMakeFiles/QuizGame.dir/src/GamePlay.cpp.o: ../src/GamePlay.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ruby/Desktop/Quiz-Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/QuizGame.dir/src/GamePlay.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QuizGame.dir/src/GamePlay.cpp.o -c /Users/ruby/Desktop/Quiz-Game/src/GamePlay.cpp

CMakeFiles/QuizGame.dir/src/GamePlay.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QuizGame.dir/src/GamePlay.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ruby/Desktop/Quiz-Game/src/GamePlay.cpp > CMakeFiles/QuizGame.dir/src/GamePlay.cpp.i

CMakeFiles/QuizGame.dir/src/GamePlay.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QuizGame.dir/src/GamePlay.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ruby/Desktop/Quiz-Game/src/GamePlay.cpp -o CMakeFiles/QuizGame.dir/src/GamePlay.cpp.s

CMakeFiles/QuizGame.dir/src/MainMenu.cpp.o: CMakeFiles/QuizGame.dir/flags.make
CMakeFiles/QuizGame.dir/src/MainMenu.cpp.o: ../src/MainMenu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ruby/Desktop/Quiz-Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/QuizGame.dir/src/MainMenu.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QuizGame.dir/src/MainMenu.cpp.o -c /Users/ruby/Desktop/Quiz-Game/src/MainMenu.cpp

CMakeFiles/QuizGame.dir/src/MainMenu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QuizGame.dir/src/MainMenu.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ruby/Desktop/Quiz-Game/src/MainMenu.cpp > CMakeFiles/QuizGame.dir/src/MainMenu.cpp.i

CMakeFiles/QuizGame.dir/src/MainMenu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QuizGame.dir/src/MainMenu.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ruby/Desktop/Quiz-Game/src/MainMenu.cpp -o CMakeFiles/QuizGame.dir/src/MainMenu.cpp.s

CMakeFiles/QuizGame.dir/src/PauseGame.cpp.o: CMakeFiles/QuizGame.dir/flags.make
CMakeFiles/QuizGame.dir/src/PauseGame.cpp.o: ../src/PauseGame.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ruby/Desktop/Quiz-Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/QuizGame.dir/src/PauseGame.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QuizGame.dir/src/PauseGame.cpp.o -c /Users/ruby/Desktop/Quiz-Game/src/PauseGame.cpp

CMakeFiles/QuizGame.dir/src/PauseGame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QuizGame.dir/src/PauseGame.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ruby/Desktop/Quiz-Game/src/PauseGame.cpp > CMakeFiles/QuizGame.dir/src/PauseGame.cpp.i

CMakeFiles/QuizGame.dir/src/PauseGame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QuizGame.dir/src/PauseGame.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ruby/Desktop/Quiz-Game/src/PauseGame.cpp -o CMakeFiles/QuizGame.dir/src/PauseGame.cpp.s

CMakeFiles/QuizGame.dir/src/StateMan.cpp.o: CMakeFiles/QuizGame.dir/flags.make
CMakeFiles/QuizGame.dir/src/StateMan.cpp.o: ../src/StateMan.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ruby/Desktop/Quiz-Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/QuizGame.dir/src/StateMan.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QuizGame.dir/src/StateMan.cpp.o -c /Users/ruby/Desktop/Quiz-Game/src/StateMan.cpp

CMakeFiles/QuizGame.dir/src/StateMan.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QuizGame.dir/src/StateMan.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ruby/Desktop/Quiz-Game/src/StateMan.cpp > CMakeFiles/QuizGame.dir/src/StateMan.cpp.i

CMakeFiles/QuizGame.dir/src/StateMan.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QuizGame.dir/src/StateMan.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ruby/Desktop/Quiz-Game/src/StateMan.cpp -o CMakeFiles/QuizGame.dir/src/StateMan.cpp.s

CMakeFiles/QuizGame.dir/src/main.cpp.o: CMakeFiles/QuizGame.dir/flags.make
CMakeFiles/QuizGame.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ruby/Desktop/Quiz-Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/QuizGame.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QuizGame.dir/src/main.cpp.o -c /Users/ruby/Desktop/Quiz-Game/src/main.cpp

CMakeFiles/QuizGame.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QuizGame.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ruby/Desktop/Quiz-Game/src/main.cpp > CMakeFiles/QuizGame.dir/src/main.cpp.i

CMakeFiles/QuizGame.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QuizGame.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ruby/Desktop/Quiz-Game/src/main.cpp -o CMakeFiles/QuizGame.dir/src/main.cpp.s

CMakeFiles/QuizGame.dir/src/Ranking.cpp.o: CMakeFiles/QuizGame.dir/flags.make
CMakeFiles/QuizGame.dir/src/Ranking.cpp.o: ../src/Ranking.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ruby/Desktop/Quiz-Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/QuizGame.dir/src/Ranking.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QuizGame.dir/src/Ranking.cpp.o -c /Users/ruby/Desktop/Quiz-Game/src/Ranking.cpp

CMakeFiles/QuizGame.dir/src/Ranking.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QuizGame.dir/src/Ranking.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ruby/Desktop/Quiz-Game/src/Ranking.cpp > CMakeFiles/QuizGame.dir/src/Ranking.cpp.i

CMakeFiles/QuizGame.dir/src/Ranking.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QuizGame.dir/src/Ranking.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ruby/Desktop/Quiz-Game/src/Ranking.cpp -o CMakeFiles/QuizGame.dir/src/Ranking.cpp.s

CMakeFiles/QuizGame.dir/src/Introduction.cpp.o: CMakeFiles/QuizGame.dir/flags.make
CMakeFiles/QuizGame.dir/src/Introduction.cpp.o: ../src/Introduction.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ruby/Desktop/Quiz-Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/QuizGame.dir/src/Introduction.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QuizGame.dir/src/Introduction.cpp.o -c /Users/ruby/Desktop/Quiz-Game/src/Introduction.cpp

CMakeFiles/QuizGame.dir/src/Introduction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QuizGame.dir/src/Introduction.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ruby/Desktop/Quiz-Game/src/Introduction.cpp > CMakeFiles/QuizGame.dir/src/Introduction.cpp.i

CMakeFiles/QuizGame.dir/src/Introduction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QuizGame.dir/src/Introduction.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ruby/Desktop/Quiz-Game/src/Introduction.cpp -o CMakeFiles/QuizGame.dir/src/Introduction.cpp.s

CMakeFiles/QuizGame.dir/src/Login.cpp.o: CMakeFiles/QuizGame.dir/flags.make
CMakeFiles/QuizGame.dir/src/Login.cpp.o: ../src/Login.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ruby/Desktop/Quiz-Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/QuizGame.dir/src/Login.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QuizGame.dir/src/Login.cpp.o -c /Users/ruby/Desktop/Quiz-Game/src/Login.cpp

CMakeFiles/QuizGame.dir/src/Login.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QuizGame.dir/src/Login.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ruby/Desktop/Quiz-Game/src/Login.cpp > CMakeFiles/QuizGame.dir/src/Login.cpp.i

CMakeFiles/QuizGame.dir/src/Login.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QuizGame.dir/src/Login.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ruby/Desktop/Quiz-Game/src/Login.cpp -o CMakeFiles/QuizGame.dir/src/Login.cpp.s

CMakeFiles/QuizGame.dir/src/MakeWish.cpp.o: CMakeFiles/QuizGame.dir/flags.make
CMakeFiles/QuizGame.dir/src/MakeWish.cpp.o: ../src/MakeWish.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ruby/Desktop/Quiz-Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/QuizGame.dir/src/MakeWish.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QuizGame.dir/src/MakeWish.cpp.o -c /Users/ruby/Desktop/Quiz-Game/src/MakeWish.cpp

CMakeFiles/QuizGame.dir/src/MakeWish.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QuizGame.dir/src/MakeWish.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ruby/Desktop/Quiz-Game/src/MakeWish.cpp > CMakeFiles/QuizGame.dir/src/MakeWish.cpp.i

CMakeFiles/QuizGame.dir/src/MakeWish.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QuizGame.dir/src/MakeWish.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ruby/Desktop/Quiz-Game/src/MakeWish.cpp -o CMakeFiles/QuizGame.dir/src/MakeWish.cpp.s

CMakeFiles/QuizGame.dir/src/GameOver.cpp.o: CMakeFiles/QuizGame.dir/flags.make
CMakeFiles/QuizGame.dir/src/GameOver.cpp.o: ../src/GameOver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ruby/Desktop/Quiz-Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/QuizGame.dir/src/GameOver.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QuizGame.dir/src/GameOver.cpp.o -c /Users/ruby/Desktop/Quiz-Game/src/GameOver.cpp

CMakeFiles/QuizGame.dir/src/GameOver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QuizGame.dir/src/GameOver.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ruby/Desktop/Quiz-Game/src/GameOver.cpp > CMakeFiles/QuizGame.dir/src/GameOver.cpp.i

CMakeFiles/QuizGame.dir/src/GameOver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QuizGame.dir/src/GameOver.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ruby/Desktop/Quiz-Game/src/GameOver.cpp -o CMakeFiles/QuizGame.dir/src/GameOver.cpp.s

# Object files for target QuizGame
QuizGame_OBJECTS = \
"CMakeFiles/QuizGame.dir/src/AssetMan.cpp.o" \
"CMakeFiles/QuizGame.dir/src/Game.cpp.o" \
"CMakeFiles/QuizGame.dir/src/GamePlay.cpp.o" \
"CMakeFiles/QuizGame.dir/src/MainMenu.cpp.o" \
"CMakeFiles/QuizGame.dir/src/PauseGame.cpp.o" \
"CMakeFiles/QuizGame.dir/src/StateMan.cpp.o" \
"CMakeFiles/QuizGame.dir/src/main.cpp.o" \
"CMakeFiles/QuizGame.dir/src/Ranking.cpp.o" \
"CMakeFiles/QuizGame.dir/src/Introduction.cpp.o" \
"CMakeFiles/QuizGame.dir/src/Login.cpp.o" \
"CMakeFiles/QuizGame.dir/src/MakeWish.cpp.o" \
"CMakeFiles/QuizGame.dir/src/GameOver.cpp.o"

# External object files for target QuizGame
QuizGame_EXTERNAL_OBJECTS =

QuizGame: CMakeFiles/QuizGame.dir/src/AssetMan.cpp.o
QuizGame: CMakeFiles/QuizGame.dir/src/Game.cpp.o
QuizGame: CMakeFiles/QuizGame.dir/src/GamePlay.cpp.o
QuizGame: CMakeFiles/QuizGame.dir/src/MainMenu.cpp.o
QuizGame: CMakeFiles/QuizGame.dir/src/PauseGame.cpp.o
QuizGame: CMakeFiles/QuizGame.dir/src/StateMan.cpp.o
QuizGame: CMakeFiles/QuizGame.dir/src/main.cpp.o
QuizGame: CMakeFiles/QuizGame.dir/src/Ranking.cpp.o
QuizGame: CMakeFiles/QuizGame.dir/src/Introduction.cpp.o
QuizGame: CMakeFiles/QuizGame.dir/src/Login.cpp.o
QuizGame: CMakeFiles/QuizGame.dir/src/MakeWish.cpp.o
QuizGame: CMakeFiles/QuizGame.dir/src/GameOver.cpp.o
QuizGame: CMakeFiles/QuizGame.dir/build.make
QuizGame: /usr/local/lib/libsfml-graphics.2.5.1.dylib
QuizGame: /usr/local/lib/libsfml-audio.2.5.1.dylib
QuizGame: /usr/local/lib/libsfml-network.2.5.1.dylib
QuizGame: /usr/local/lib/libsfml-window.2.5.1.dylib
QuizGame: /usr/local/lib/libsfml-system.2.5.1.dylib
QuizGame: CMakeFiles/QuizGame.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ruby/Desktop/Quiz-Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable QuizGame"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/QuizGame.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/QuizGame.dir/build: QuizGame
.PHONY : CMakeFiles/QuizGame.dir/build

CMakeFiles/QuizGame.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/QuizGame.dir/cmake_clean.cmake
.PHONY : CMakeFiles/QuizGame.dir/clean

CMakeFiles/QuizGame.dir/depend:
	cd /Users/ruby/Desktop/Quiz-Game/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ruby/Desktop/Quiz-Game /Users/ruby/Desktop/Quiz-Game /Users/ruby/Desktop/Quiz-Game/cmake-build-debug /Users/ruby/Desktop/Quiz-Game/cmake-build-debug /Users/ruby/Desktop/Quiz-Game/cmake-build-debug/CMakeFiles/QuizGame.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/QuizGame.dir/depend

