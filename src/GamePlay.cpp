#include "../include/GamePlay.h"
#include "../include/PauseGame.h"
#include "../include/MakeWish.h"
#include "../include/GameOver.h"



#include <SFML/Window/Event.hpp>

#include <stdlib.h>
#include <cmath>

#include <iostream>


GamePlay::GamePlay(std::shared_ptr<Context> &context)
        : m_context(context),
          m_releaseQuestion(true),
          m_questionNumber(0),
          m_isAButtonSelected(false),
          m_isBButtonSelected(false),
          m_isCButtonSelected(false),
          m_isDButtonSelected(false),
          m_isPauseSelected(false),
          m_isAButtonPressed(false),
          m_isBButtonPressed(false),
          m_isCButtonPressed(false),
          m_isDButtonPressed(false),
          m_isChoiceButtonPressed(false),
          m_isPausePressed(false),
          m_score(0),
          m_level(1),
          m_answer(""),
          m_quesFile("assets/QA/question_utf8.txt"), m_optFile("assets/QA/options_utf8.txt"), m_answerFile("assets/QA/answer_ansi.txt"),
          ques_vec(),option_vec(),answer_vec(),
          option_line(""), option(""),
          answer_char(""),
          m_pickQuestion(0),
          m_lifeRemain(5),
          m_startTime(0),
          m_totalNumAnswered(0)
{
    srand(time(nullptr));
}

GamePlay::~GamePlay()
{
}

bool GamePlay::IsTextSelected(sf::Text object)
{
    int obj_x = object.getPosition().x, obj_y = object.getPosition().y;
    int obj_w = object.getGlobalBounds().width, obj_h = object.getGlobalBounds().height;
    sf::Vector2<int> mouse_pos = sf::Mouse::getPosition(*m_context->m_window);
    int mouse_x = mouse_pos.x, mouse_y = mouse_pos.y;
    if (abs(mouse_x - obj_x) <= obj_w / 2 && abs(mouse_y - obj_y) <= obj_h / 2)
        return true;
    else
        return false;
}


bool GamePlay::IsTextClicked(sf::Text object, sf::Mouse::Button button)
{
    if (sf::Mouse::isButtonPressed(button) && IsTextSelected(object))
        return true;
    return false;
}

void GamePlay::Init()
{
    m_context->m_assets->AddFont(MAIN_FONT, "assets/fonts/NotoSerifTC-Medium.otf");
    // Question title
    m_questionTitle.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_questionTitle.setOrigin(m_questionTitle.getLocalBounds().width / 2,
                               m_questionTitle.getLocalBounds().height / 2);
    m_questionTitle.setPosition(m_context->m_window->getSize().x / 2 - 120.f,
                            m_context->m_window->getSize().y / 2 - 330.f);
    m_questionTitle.setCharacterSize(54);

    // Question content
    m_questionContent.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_questionContent.setOrigin(m_questionContent.getLocalBounds().width / 2,
                                 m_questionContent.getLocalBounds().height / 2);
    m_questionContent.setPosition(m_context->m_window->getSize().x / 2 - 220.f,
                                 m_context->m_window->getSize().y / 2 - 200.f);
    m_questionContent.setCharacterSize(30);

    // Button
    m_aButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_aButton.setOrigin(m_aButton.getLocalBounds().width / 2,
                        m_aButton.getLocalBounds().height / 2);
    m_aButton.setPosition(m_context->m_window->getSize().x / 2 - 50.f,
                             m_context->m_window->getSize().y / 2 - 25.f);
    m_aButton.setCharacterSize(30);

    m_bButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_bButton.setOrigin(m_bButton.getLocalBounds().width / 2,
                        m_bButton.getLocalBounds().height / 2);
    m_bButton.setPosition(m_context->m_window->getSize().x / 2 - 50.f,
                          m_context->m_window->getSize().y / 2 + 50.f);
    m_bButton.setCharacterSize(30);

    m_cButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_cButton.setOrigin(m_cButton.getLocalBounds().width / 2,
                        m_cButton.getLocalBounds().height / 2);
    m_cButton.setPosition(m_context->m_window->getSize().x / 2 - 50.f,
                          m_context->m_window->getSize().y / 2 + 125.f);
    m_cButton.setCharacterSize(30);

    m_dButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_dButton.setOrigin(m_dButton.getLocalBounds().width / 2,
                        m_dButton.getLocalBounds().height / 2);
    m_dButton.setPosition(m_context->m_window->getSize().x / 2 - 50.f,
                          m_context->m_window->getSize().y / 2 + 200.f);
    m_dButton.setCharacterSize(30);

    m_pauseButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_pauseButton.setString(L"暫停");
    m_pauseButton.setOrigin(m_pauseButton.getLocalBounds().width / 2,
                        m_pauseButton.getLocalBounds().height / 2);
    m_pauseButton.setPosition(m_context->m_window->getSize().x / 2 - 460.f,
                          m_context->m_window->getSize().y / 2  + 337.f);
    m_pauseButton.setCharacterSize(40);

    // level
    m_levelText.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_levelText.setString("Level : " + std::to_string(m_level));
    m_levelText.setCharacterSize(40);

    // life
    m_lifeText.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_lifeText.setString("Life Remain : " + std::to_string(m_lifeRemain));
    m_lifeText.setOrigin(m_lifeText.getLocalBounds().width / 2,
                         m_lifeText.getLocalBounds().height / 2);
    m_lifeText.setPosition(m_context->m_window->getSize().x / 2 - 388.f,
                          m_context->m_window->getSize().y / 2 - 300.f);
    m_lifeText.setCharacterSize(40);

    // Time Remain Text
    m_timeRemainText.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_timeRemainText.setOrigin(m_lifeText.getLocalBounds().width / 2,
                         m_lifeText.getLocalBounds().height / 2);
    m_timeRemainText.setPosition(m_context->m_window->getSize().x / 2 + 600.f,
                           m_context->m_window->getSize().y / 2 - 350.f);
    m_timeRemainText.setCharacterSize(40);
    // Read files
    if(m_quesFile)
    {
        while(std::getline(m_quesFile, quesStr))
            ques_vec.push_back(quesStr);
    }
    m_quesFile.close();

    int index_vector = 0;
    if(m_optFile)
    {
        // changing the line (type: string) to input stream
        while (getline(m_optFile, option_line,'\n'))
        {
            std::istringstream templine(option_line);
            option_vec.push_back(std::vector<std::string>()); // pushback an empty string vector
            index_vector += 1;
            while(getline(templine, option, ','))
                option_vec[index_vector - 1].push_back(option);
        }
    }
    m_optFile.close();

    if(m_answerFile)
    {
        while(m_answerFile >> answer_char)
            answer_vec.push_back(answer_char);
    }
    m_answerFile.close();

    //Sprite
    m_context->m_assets->AddTexture(FIRST, "assets/textures/1.png");
    m_first.setTexture(m_context->m_assets->GetTexture(FIRST));
    m_first.setPosition(m_context->m_window->getSize().x / 2 + 250.f, m_context->m_window->getSize().y / 2 - 250.f);

    m_context->m_assets->AddTexture(SECOND, "assets/textures/2.png");
    m_second.setTexture(m_context->m_assets->GetTexture(SECOND));
    m_second.setPosition(m_context->m_window->getSize().x / 2 + 250.f, m_context->m_window->getSize().y / 2 - 250.f);

    m_context->m_assets->AddTexture(THIRD, "assets/textures/3.png");
    m_third.setTexture(m_context->m_assets->GetTexture(THIRD));
    m_third.setPosition(m_context->m_window->getSize().x / 2 + 250.f, m_context->m_window->getSize().y / 2 - 250.f);

    m_context->m_assets->AddTexture(FOURTH, "assets/textures/4.png");
    m_fourth.setTexture(m_context->m_assets->GetTexture(FOURTH));
    m_fourth.setPosition(m_context->m_window->getSize().x / 2 + 250.f, m_context->m_window->getSize().y / 2 - 250.f);

    m_context->m_assets->AddTexture(FIFTH, "assets/textures/5.png");
    m_fifth.setTexture(m_context->m_assets->GetTexture(FIFTH));
    m_fifth.setPosition(m_context->m_window->getSize().x / 2 + 250.f, m_context->m_window->getSize().y / 2 - 250.f);

    m_context->m_assets->AddTexture(SIXTH, "assets/textures/6.png");
    m_sixth.setTexture(m_context->m_assets->GetTexture(SIXTH));
    m_sixth.setPosition(m_context->m_window->getSize().x / 2 + 250.f, m_context->m_window->getSize().y / 2 - 250.f);

    m_context->m_assets->AddTexture(SEVENTH, "assets/textures/7-1.png");
    m_seventh.setTexture(m_context->m_assets->GetTexture(SEVENTH));
    m_seventh.setPosition(m_context->m_window->getSize().x / 2 + 250.f, m_context->m_window->getSize().y / 2 - 250.f);

    if (!wrongBuffer.loadFromFile("assets/music/wrong.ogg"))
        std::cout << "ERROR"<< '\n';
    m_wrongSound.setBuffer(wrongBuffer);
    if (!correctBuffer.loadFromFile("assets/music/correct.ogg"))
        std::cout << "ERROR"<< '\n';
    m_correctSound.setBuffer(correctBuffer);
}


void GamePlay::ProcessInput()
{
    sf::Event event;
    while (m_context->m_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            m_context->m_window->close();

        if (IsTextSelected(m_aButton))
        {
            m_isAButtonSelected = true;
            m_isBButtonSelected = false;
            m_isCButtonSelected = false;
            m_isDButtonSelected = false;
            m_isPauseSelected = false;
            m_isButtonSelected = true;

        }
        else if (IsTextSelected(m_bButton))
        {
            m_isAButtonSelected = false;
            m_isBButtonSelected = true;
            m_isCButtonSelected = false;
            m_isDButtonSelected = false;
            m_isPauseSelected = false;
            m_isButtonSelected = true;
        }
        else if (IsTextSelected(m_cButton))
        {
            m_isAButtonSelected = false;
            m_isBButtonSelected = false;
            m_isCButtonSelected = true;
            m_isDButtonSelected = false;
            m_isPauseSelected = false;
            m_isButtonSelected = true;
        }
        else if (IsTextSelected(m_dButton))
        {
            m_isAButtonSelected = false;
            m_isBButtonSelected = false;
            m_isCButtonSelected = false;
            m_isDButtonSelected = true;
            m_isPauseSelected = false;
            m_isButtonSelected = true;
        }
        else if (IsTextSelected(m_pauseButton))
        {
            m_isAButtonSelected = false;
            m_isBButtonSelected = false;
            m_isCButtonSelected = false;
            m_isDButtonSelected = false;
            m_isPauseSelected = true;
            m_isButtonSelected = true;
        }
        else
        {
            m_isAButtonSelected = false;
            m_isBButtonSelected = false;
            m_isCButtonSelected = false;
            m_isDButtonSelected = false;
            m_isPauseSelected = false;
            m_isButtonSelected = false;
        }

        // TODO:點擊範圍太小，要點字體最上方
        if (IsTextClicked(m_aButton, sf::Mouse::Left))
        {
            m_isAButtonPressed = true;
            m_isBButtonPressed = false;
            m_isCButtonPressed = false;
            m_isDButtonPressed = false;
            m_isPausePressed = false;
            m_isChoiceButtonPressed = true;
        }
        else if (IsTextClicked(m_bButton, sf::Mouse::Left))
        {
            m_isAButtonPressed = false;
            m_isBButtonPressed = true;
            m_isCButtonPressed = false;
            m_isDButtonPressed = false;
            m_isPausePressed = false;
            m_isChoiceButtonPressed = true;
        }
        else if (IsTextClicked(m_cButton, sf::Mouse::Left))
        {
            m_isAButtonPressed = false;
            m_isBButtonPressed = false;
            m_isCButtonPressed = true;
            m_isDButtonPressed = false;
            m_isPausePressed = false;
            m_isChoiceButtonPressed = true;
        }
        else if (IsTextClicked(m_dButton, sf::Mouse::Left))
        {
            m_isAButtonPressed = false;
            m_isBButtonPressed = false;
            m_isCButtonPressed = false;
            m_isDButtonPressed = true;
            m_isPausePressed = false;
            m_isChoiceButtonPressed = true;
        }
        else if (IsTextClicked(m_pauseButton, sf::Mouse::Left))
        {
            m_isAButtonPressed = false;
            m_isBButtonPressed = false;
            m_isCButtonPressed = false;
            m_isDButtonPressed = false;
            m_isPausePressed = true;
        }
        else if (!m_isButtonSelected)
        {
            m_isAButtonPressed = false;
            m_isBButtonPressed = false;
            m_isCButtonPressed = false;
            m_isDButtonPressed = false;
            m_isPausePressed = false;
            m_isChoiceButtonPressed = false;
        }
    }
}

void GamePlay::Update(sf::Time deltaTime)
{
    if(!m_isPausePressed && m_score < 7 && m_lifeRemain > 0)
    {
        if (m_releaseQuestion)
        {
            m_questionNumber += 1;
            m_questionTitle.setString("Question " + std::to_string(m_questionNumber));
            // random pick question
            m_pickQuestion = (rand() % 24) + (m_level - 1) * 24;
            /*int quesLength = ques_vec[m_pickQuestion].length();
            std::string s = "";
            for (int i = 0; i < quesLength; i++)
            {
                if (i == 0 || i % 10 != 0)
                    s.push_back(ques_vec[m_pickQuestion][i]);
                else if (i % 10 == 0)
                {
                    s.push_back("\n");
                    s.push_back(ques_vec[m_pickQuestion][i]);
                }
            }
            std::cout << ques_vec[m_pickQuestion][0];*/
            sf::String question = sf::String::fromUtf8(ques_vec[m_pickQuestion].begin(), ques_vec[m_pickQuestion].end());
            sf::String aOption = sf::String::fromUtf8(option_vec[m_pickQuestion][0].begin(), option_vec[m_pickQuestion][0].end());
            sf::String bOption = sf::String::fromUtf8(option_vec[m_pickQuestion][1].begin(), option_vec[m_pickQuestion][1].end());
            sf::String cOption = sf::String::fromUtf8(option_vec[m_pickQuestion][2].begin(), option_vec[m_pickQuestion][2].end());
            sf::String dOption = sf::String::fromUtf8(option_vec[m_pickQuestion][3].begin(), option_vec[m_pickQuestion][3].end());

            m_questionContent.setString(question);
            m_aButton.setString(aOption);
            m_bButton.setString(bOption);
            m_cButton.setString(cOption);
            m_dButton.setString(dOption);

            m_answer = answer_vec[m_pickQuestion];
            m_releaseQuestion = false;
            m_startTime = time(NULL);
            m_totalNumAnswered += 1;
        }

        //std::cout << ' ' << time(NULL) << ' ' << m_startTime << '\n';
        time_t timeElapsed = time(NULL) - m_startTime;
        time_t timeRemain = 10 - timeElapsed;
        m_timeRemainText.setString(std::to_string(timeRemain));
        if (timeRemain <= 0)
        {
            m_lifeRemain -= 1;
            if (m_level <= 1)
                m_level = 1;
            else
                m_level -= 1;
            m_releaseQuestion = true;
            (*m_context->m_userInfoVec)[*m_context->m_currUserindex].TimeUsed += static_cast<int>(timeElapsed);
            m_levelText.setString("Level : " + std::to_string(m_level));
            m_lifeText.setString("Life Remain : " + std::to_string(m_lifeRemain));
        }

        // Color the buttons
        if(m_isAButtonSelected)
        {
            m_aButton.setFillColor(sf::Color::Black);
            m_bButton.setFillColor(sf::Color::White);
            m_cButton.setFillColor(sf::Color::White);
            m_dButton.setFillColor(sf::Color::White);
            m_pauseButton.setFillColor(sf::Color::White);
        }
        else if (m_isBButtonSelected)
        {
            m_aButton.setFillColor(sf::Color::White);
            m_bButton.setFillColor(sf::Color::Black);
            m_cButton.setFillColor(sf::Color::White);
            m_dButton.setFillColor(sf::Color::White);
            m_pauseButton.setFillColor(sf::Color::White);

        }
        else if (m_isCButtonSelected)
        {
            m_aButton.setFillColor(sf::Color::White);
            m_bButton.setFillColor(sf::Color::White);
            m_cButton.setFillColor(sf::Color::Black);
            m_dButton.setFillColor(sf::Color::White);
            m_pauseButton.setFillColor(sf::Color::White);

        }
        else if (m_isDButtonSelected)
        {
            m_aButton.setFillColor(sf::Color::White);
            m_bButton.setFillColor(sf::Color::White);
            m_cButton.setFillColor(sf::Color::White);
            m_dButton.setFillColor(sf::Color::Black);
            m_pauseButton.setFillColor(sf::Color::White);

        }
        else if (m_isPauseSelected)
        {
            m_aButton.setFillColor(sf::Color::White);
            m_bButton.setFillColor(sf::Color::White);
            m_cButton.setFillColor(sf::Color::White);
            m_dButton.setFillColor(sf::Color::White);
            m_pauseButton.setFillColor(sf::Color::Black);
        }

        else
        {
            m_aButton.setFillColor(sf::Color::White);
            m_bButton.setFillColor(sf::Color::White);
            m_cButton.setFillColor(sf::Color::White);
            m_dButton.setFillColor(sf::Color::White);
            m_pauseButton.setFillColor(sf::Color::White);
        }

        if (m_isChoiceButtonPressed && !sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if ((m_isAButtonPressed && m_answer == "A") || (m_isBButtonPressed && m_answer == "B")
                || (m_isCButtonPressed && m_answer == "C") || (m_isDButtonPressed && m_answer == "D"))
            {
                m_correctSound.play();
                //while (m_correctSound.getStatus() == sf::Music::Playing);
                sf::sleep(sf::seconds(0.3f));
                m_level += 1;
            }
            else if ((m_isAButtonPressed && m_answer != "A") || (m_isBButtonPressed && m_answer != "B")
                     || (m_isCButtonPressed && m_answer != "C") || (m_isDButtonPressed && m_answer != "D"))
            {
                m_wrongSound.play();
                //while (m_wrongSound.getStatus() == sf::Music::Playing);
                sf::sleep(sf::seconds(0.3f)); // second
                m_lifeRemain -= 1;
                if (m_level <= 1)
                    m_level = 1;
                else
                    m_level -= 1;
            }
            m_levelText.setString("Level : " + std::to_string(m_level));
            m_lifeText.setString("Life Remain : " + std::to_string(m_lifeRemain));
            m_releaseQuestion = true;
            m_isAButtonPressed = false;
            m_isBButtonPressed = false;
            m_isCButtonPressed = false;
            m_isDButtonPressed = false;
            m_isPausePressed = false;
            m_isChoiceButtonPressed = false;
            (*m_context->m_userInfoVec)[*m_context->m_currUserindex].TimeUsed += static_cast<int>(timeElapsed);
        }
    }
    else
        m_context->m_states->Add(std::make_unique<PauseGame>(m_context));

    if (m_level >= 7 && m_lifeRemain > 0)
    {
        (*m_context->m_userInfoVec)[*m_context->m_currUserindex].TotalQuesAnswered += m_totalNumAnswered;
        (*m_context->m_userInfoVec)[*m_context->m_currUserindex].Life = m_lifeRemain;
        (*m_context->m_userInfoVec)[*m_context->m_currUserindex].CompleteStatus = true;
        (*m_context->m_userInfoVec)[*m_context->m_currUserindex].CurrentLv = m_level;
        (*m_context->m_userInfoVec)[*m_context->m_currUserindex].Wish = '*';
        (*m_context->m_userInfoVec)[*m_context->m_currUserindex].WishStatus = true;
        (*m_context->m_userInfoVec)[*m_context->m_currUserindex].BannedStatus = false;
        //tmp_info.TimeUsed = 0;
        (*m_context->m_userInfoVec)[*m_context->m_currUserindex].BannedTime = 0;
        m_context->m_states->Add(std::make_unique<MakeWish>(m_context));
    }
    if (m_level < 7 && m_lifeRemain <= 0)
    {
        (*m_context->m_userInfoVec)[*m_context->m_currUserindex].TotalQuesAnswered += m_totalNumAnswered;
        (*m_context->m_userInfoVec)[*m_context->m_currUserindex].Life = m_lifeRemain;
        (*m_context->m_userInfoVec)[*m_context->m_currUserindex].CompleteStatus = false;
        (*m_context->m_userInfoVec)[*m_context->m_currUserindex].CurrentLv = m_level;
        (*m_context->m_userInfoVec)[*m_context->m_currUserindex].Wish = '*';
        (*m_context->m_userInfoVec)[*m_context->m_currUserindex].WishStatus = false;
        (*m_context->m_userInfoVec)[*m_context->m_currUserindex].BannedStatus = true;
        //tmp_info.TimeUsed = 0;
        //tmp_info.BannedTime = 0;
        m_context->m_states->Add(std::make_unique<GameOver>(m_context));
    }

}

void GamePlay::Draw()
{
    m_context->m_window->clear(sf::Color::Blue);
    m_context->m_window->draw(m_questionTitle);
    m_context->m_window->draw(m_questionContent);
    m_context->m_window->draw(m_aButton);
    m_context->m_window->draw(m_bButton);
    m_context->m_window->draw(m_cButton);
    m_context->m_window->draw(m_dButton);
    m_context->m_window->draw(m_pauseButton);
    m_context->m_window->draw(m_welcomeUser);
    m_context->m_window->draw(m_levelText);
    m_context->m_window->draw(m_lifeText);
    m_context->m_window->draw(m_timeRemainText);
    if (m_level == 1)
        m_context->m_window->draw(m_first);
    if (m_level == 2)
        m_context->m_window->draw(m_second);
    if (m_level == 3)
        m_context->m_window->draw(m_third);
    if (m_level == 4)
        m_context->m_window->draw(m_fourth);
    if (m_level == 5)
        m_context->m_window->draw(m_fifth);
    if (m_level == 6)
        m_context->m_window->draw(m_sixth);
    if (m_level == 7)
        m_context->m_window->draw(m_seventh);


    m_context->m_window->display();
}

void GamePlay::Pause()
{
    m_isPausePressed = true;
}

void GamePlay::Start()
{
    m_isPausePressed = false;
}