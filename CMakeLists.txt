cmake_minimum_required(VERSION 3.20)
project(QuizGame)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_OUTPUT_RUNTIME_DIRECTORY /Users/ruby/Desktop/Quiz-Game)

add_executable(QuizGame src/AssetMan.cpp src/Game.cpp src/GamePlay.cpp
        src/MainMenu.cpp src/PauseGame.cpp src/StateMan.cpp src/main.cpp
        src/Ranking.cpp src/Introduction.cpp src/Login.cpp src/MakeWish.cpp src/GameOver.cpp src/Welcome.cpp src/Register.cpp include/Register.h src/InternalWelcome.cpp include/InternalWelcome.h src/PlayerInfo.cpp include/PlayerInfo.h)

include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(QuizGame sfml-system sfml-window sfml-graphics sfml-audio sfml-network)