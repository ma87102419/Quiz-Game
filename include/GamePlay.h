#pragma once

#include <memory>
#include <array>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <ctime>

#include "Game.h"
#include "State.h"

#define TIME_LIMIT 10;


class GamePlay : public Engine::State
{
private:
    std::shared_ptr<Context> m_context;
    sf::Text m_questionTitle;
    sf::Text m_questionContent;
    sf::Text m_aButton;
    sf::Text m_bButton;
    sf::Text m_cButton;
    sf::Text m_dButton;
    sf::Text m_pauseButton;
    sf::Text m_levelText;
    sf::Text m_lifeText;
    sf::Text m_welcomeUser;
    sf::Text m_timeRemainText;

    sf::SoundBuffer wrongBuffer;
    sf::Sound m_wrongSound;
    sf::SoundBuffer correctBuffer;
    sf::Sound m_correctSound;

    sf::Sprite m_first;
    sf::Sprite m_second;
    sf::Sprite m_third;
    sf::Sprite m_fourth;
    sf::Sprite m_fifth;
    sf::Sprite m_sixth;
    sf::Sprite m_seventh;

    bool m_releaseQuestion;

    bool m_isAButtonSelected;
    bool m_isBButtonSelected;
    bool m_isCButtonSelected;
    bool m_isDButtonSelected;
    bool m_isPauseSelected;
    bool m_isButtonSelected;
    bool m_isAButtonPressed;
    bool m_isBButtonPressed;
    bool m_isCButtonPressed;
    bool m_isDButtonPressed;
    bool m_isChoiceButtonPressed;
    bool m_isPausePressed;

    time_t m_startTime;
    int m_score;
    int m_level;
    int m_pickQuestion;
    int m_lifeRemain;
    int m_questionNumber;
    int m_totalNumAnswered;

    std::ifstream m_quesFile;
    std::ifstream m_optFile;
    std::ifstream m_answerFile;
    std::string quesStr;
    std::string option_line;
    std::string option;
    std::string answer_char;
    std::string m_answer;

    std::vector<std::string> ques_vec;
    std::vector<std::vector<std::string>> option_vec; // a two dimensional vector storing options (4 options)
    std::vector<std::string> answer_vec; // a single dimensional vector storing the answer of the answer to the question;

    bool IsTextSelected(sf::Text object);
    bool IsTextClicked(sf::Text object, sf::Mouse::Button button);

public:
    GamePlay(std::shared_ptr<Context> &context);
    ~GamePlay();

    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltaTime) override;
    void Draw() override;
    void Pause() override;
    void Start() override;
};