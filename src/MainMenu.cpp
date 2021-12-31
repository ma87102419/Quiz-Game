#include "../include/MainMenu.h"
#include "../include/Introduction.h"
#include "../include/Ranking.h"
#include "../include/Login.h"

#include <SFML/Window/Event.hpp>
#include <cmath>


MainMenu::MainMenu(std::shared_ptr<Context> &context)
        : m_context(context), m_isPlayButtonSelected(true),
          m_isPlayButtonPressed(false), m_isExitButtonSelected(false),
          m_isExitButtonPressed(false), m_isRankButtonSelected(false), m_isRankButtonPressed(false),
          m_isIntroButtonSelected(false), m_isIntroButtonPressed(false)
{
}

MainMenu::~MainMenu()
{
}


bool MainMenu::IsTextSelected(sf::Text object)
{
    int obj_x = object.getPosition().x, obj_y = object.getPosition().y;
    int obj_w = object.getGlobalBounds().width, obj_h = object.getGlobalBounds().height;
    sf::Vector2<int> mouse_pos = sf::Mouse::getPosition(*m_context->m_window);
    int mouse_x = mouse_pos.x, mouse_y = mouse_pos.y;
    if (abs(mouse_x - obj_x) <= obj_w / 2 && abs(mouse_y - obj_y) <= obj_h / 2)
        return true;
}


bool MainMenu::IsTextClicked(sf::Text object, sf::Mouse::Button button)
{
    if (sf::Mouse::isButtonPressed(button) && IsTextSelected(object))
        return true;
    return false;
}


void MainMenu::Init()
{
    m_context->m_assets->AddFont(MAIN_FONT, "/Users/ruby/Desktop/FinalQuizGame/assets/fonts/NotoSerifTC-Medium.otf");
    // Title
    m_gameTitle.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_gameTitle.setString("Quiz Game");
    m_gameTitle.setOrigin(m_gameTitle.getLocalBounds().width / 2,
                          m_gameTitle.getLocalBounds().height / 2);
    m_gameTitle.setPosition(m_context->m_window->getSize().x / 2,
                            m_context->m_window->getSize().y / 2 - 150.f);

    // Play Button
    m_playButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_playButton.setString("Play");
    m_playButton.setOrigin(m_playButton.getLocalBounds().width / 2,
                           m_playButton.getLocalBounds().height / 2);
    m_playButton.setPosition(m_context->m_window->getSize().x / 2,
                             m_context->m_window->getSize().y / 2 - 25.f);
    m_playButton.setCharacterSize(20);

    // Ranking Button
    m_rankButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_rankButton.setString("Ranking");
    m_rankButton.setOrigin(m_rankButton.getLocalBounds().width / 2,
                           m_rankButton.getLocalBounds().height / 2);
    m_rankButton.setPosition(m_context->m_window->getSize().x / 2,
                             m_context->m_window->getSize().y / 2);
    m_rankButton.setCharacterSize(20);

    // Intro Button
    m_introButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_introButton.setString("Introduction");
    m_introButton.setOrigin(m_introButton.getLocalBounds().width / 2,
                           m_introButton.getLocalBounds().height / 2);
    m_introButton.setPosition(m_context->m_window->getSize().x / 2,
                             m_context->m_window->getSize().y / 2 + 25.f);
    m_introButton.setCharacterSize(20);

    // Exit Button
    m_exitButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_exitButton.setString("Exit");
    m_exitButton.setOrigin(m_exitButton.getLocalBounds().width / 2,
                           m_exitButton.getLocalBounds().height / 2);
    m_exitButton.setPosition(m_context->m_window->getSize().x / 2,
                             m_context->m_window->getSize().y / 2 + 50.f);
    m_exitButton.setCharacterSize(20);
}


void MainMenu::ProcessInput()
{
    sf::Event event;
    while (m_context->m_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_context->m_window->close();
        }

        if (IsTextSelected(m_playButton))
        {
            m_isPlayButtonSelected = true;
            m_isRankButtonSelected = false;
            m_isIntroButtonSelected = false;
            m_isExitButtonSelected = false;

        }
        else if (IsTextSelected(m_rankButton))
        {
            m_isPlayButtonSelected = false;
            m_isRankButtonSelected = true;
            m_isIntroButtonSelected = false;
            m_isExitButtonSelected = false;
        }
        else if (IsTextSelected(m_introButton))
        {
            m_isPlayButtonSelected = false;
            m_isRankButtonSelected = false;
            m_isIntroButtonSelected = true;
            m_isExitButtonSelected = false;
        }
        else if (IsTextSelected(m_exitButton))
        {
            m_isPlayButtonSelected = false;
            m_isRankButtonSelected = false;
            m_isIntroButtonSelected = false;
            m_isExitButtonSelected = true;
        }
        else
        {
            m_isPlayButtonSelected = false;
            m_isRankButtonSelected = false;
            m_isIntroButtonSelected = false;
            m_isExitButtonSelected = false;
        }

        if (IsTextClicked(m_playButton, sf::Mouse::Left))
        {
            m_isPlayButtonPressed = true;
            m_isRankButtonPressed = false;
            m_isIntroButtonPressed = false;
            m_isExitButtonPressed = false;
        }
        else if (IsTextClicked(m_rankButton, sf::Mouse::Left))
        {
            m_isPlayButtonPressed = false;
            m_isRankButtonPressed = true;
            m_isIntroButtonPressed = false;
            m_isExitButtonPressed = false;
        }
        else if (IsTextClicked(m_introButton, sf::Mouse::Left))
        {
            m_isPlayButtonPressed = false;
            m_isRankButtonPressed = false;
            m_isIntroButtonPressed = true;
            m_isExitButtonPressed = false;
        }
        else if (IsTextClicked(m_exitButton, sf::Mouse::Left))
        {
            m_isPlayButtonPressed = false;
            m_isRankButtonPressed = false;
            m_isIntroButtonPressed = false;
            m_isExitButtonPressed = true;
        }
        else
        {
            m_isPlayButtonPressed = false;
            m_isRankButtonPressed = false;
            m_isIntroButtonPressed = false;
            m_isExitButtonPressed = false;
        }


    }
}

void MainMenu::Update(sf::Time deltaTime)
{
    if(m_isPlayButtonSelected)
    {
        m_playButton.setFillColor(sf::Color::Black);
        m_rankButton.setFillColor(sf::Color::White);
        m_introButton.setFillColor(sf::Color::White);
        m_exitButton.setFillColor(sf::Color::White);
    }
    else if (m_isRankButtonSelected)
    {
        m_playButton.setFillColor(sf::Color::White);
        m_rankButton.setFillColor(sf::Color::Black);
        m_introButton.setFillColor(sf::Color::White);
        m_exitButton.setFillColor(sf::Color::White);
    }
    else if (m_isIntroButtonSelected)
    {
        m_playButton.setFillColor(sf::Color::White);
        m_rankButton.setFillColor(sf::Color::White);
        m_introButton.setFillColor(sf::Color::Black);
        m_exitButton.setFillColor(sf::Color::White);
    }
    else if (m_isExitButtonSelected)
    {
        m_playButton.setFillColor(sf::Color::White);
        m_rankButton.setFillColor(sf::Color::White);
        m_introButton.setFillColor(sf::Color::White);
        m_exitButton.setFillColor(sf::Color::Black);
    }
    else
    {
        m_playButton.setFillColor(sf::Color::White);
        m_rankButton.setFillColor(sf::Color::White);
        m_introButton.setFillColor(sf::Color::White);
        m_exitButton.setFillColor(sf::Color::White);
    }

    if(m_isPlayButtonPressed)
    {
        m_context->m_states->PopCurrent();
        m_context->m_states->Add(std::make_unique<Login>(m_context), true);
    }
    else if (m_isRankButtonPressed)
    {
        m_context->m_states->PopCurrent();
        m_context->m_states->Add(std::make_unique<Ranking>(m_context), true);
    }
    else if (m_isIntroButtonPressed)
    {
        m_context->m_states->PopCurrent();
        m_context->m_states->Add(std::make_unique<Introduction>(m_context), true);
    }
    else if(m_isExitButtonPressed)
        m_context->m_window->close();

}

void MainMenu::Draw()
{
    m_context->m_window->clear(sf::Color::Blue);
    m_context->m_window->draw(m_gameTitle);
    m_context->m_window->draw(m_playButton);
    m_context->m_window->draw(m_rankButton);
    m_context->m_window->draw(m_introButton);
    m_context->m_window->draw(m_exitButton);
    m_context->m_window->display();
}