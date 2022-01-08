#include "../include/MainMenu.h"
#include "../include/Introduction.h"
#include "../include/Ranking.h"
#include "../include/Welcome.h"
#include "../include/MakeWish.h"

#include <SFML/Window/Event.hpp>
#include <cmath>
#include<iostream>


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
    else
        return false;
}


bool MainMenu::IsTextClicked(sf::Text object, sf::Mouse::Button button)
{
    if (sf::Mouse::isButtonPressed(button) && IsTextSelected(object))
        return true;
    return false;
}


void MainMenu::Init()
{
    m_context->m_assets->AddFont(MAIN_FONT, "assets/fonts/NotoSerifTC-Medium.otf");
    // Title
    m_gameTitle.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_gameTitle.setString(L"台大知識王");
    m_gameTitle.setFillColor(sf::Color::Black);
    m_gameTitle.setOrigin(m_gameTitle.getLocalBounds().width / 2,
                          m_gameTitle.getLocalBounds().height / 2);
    m_gameTitle.setPosition(m_context->m_window->getSize().x / 2 - 45.f,
                            m_context->m_window->getSize().y / 2 - 330.f);
    m_gameTitle.setCharacterSize(54);

    // Play Button
    m_playButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_playButton.setString(L"開始遊戲");
    m_playButton.setFillColor(sf::Color::Black); // change color of the text
    m_playButton.setOrigin(m_playButton.getLocalBounds().width / 2,
                           m_playButton.getLocalBounds().height / 2);
    m_playButton.setPosition(m_context->m_window->getSize().x / 2,
                             m_context->m_window->getSize().y / 2 - 150.f);
    m_playButton.setCharacterSize(40);

    // Ranking Button
    m_rankButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_rankButton.setString(L"願望清單");
    m_rankButton.setFillColor(sf::Color::Black);
    m_rankButton.setOrigin(m_rankButton.getLocalBounds().width / 2,
                           m_rankButton.getLocalBounds().height / 2);
    m_rankButton.setPosition(m_context->m_window->getSize().x / 2,
                             m_context->m_window->getSize().y / 2 - 75.f);
    m_rankButton.setCharacterSize(40);

    // Intro Button
    m_introButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_introButton.setString(L"遊戲介紹");
    m_introButton.setFillColor(sf::Color::Black);
    m_introButton.setOrigin(m_introButton.getLocalBounds().width / 2,
                           m_introButton.getLocalBounds().height / 2);
    m_introButton.setPosition(m_context->m_window->getSize().x / 2 - 10.f,
                             m_context->m_window->getSize().y / 2);
    m_introButton.setCharacterSize(40);

    // Exit Button
    m_exitButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_exitButton.setString(L"退出遊戲");
    m_exitButton.setFillColor(sf::Color::Black);
    m_exitButton.setOrigin(m_exitButton.getLocalBounds().width / 2,
                           m_exitButton.getLocalBounds().height / 2);
    m_exitButton.setPosition(m_context->m_window->getSize().x / 2,
                             m_context->m_window->getSize().y / 2 + 75.f);
    m_exitButton.setCharacterSize(40);

    // load image
    if (!m_bgImage.loadFromFile("assets/background/original_light_new.jpg"))// background image
        std::cout << "no data exists!"; 
    m_bgIamgeDraw.setTexture(m_bgImage);
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
        m_playButton.setFillColor(sf::Color(121,2,2));// dark red
        m_rankButton.setFillColor(sf::Color::Black);
        m_introButton.setFillColor(sf::Color::Black);
        m_exitButton.setFillColor(sf::Color::Black);
    }
    else if (m_isRankButtonSelected)
    {
        m_playButton.setFillColor(sf::Color::Black);
        m_rankButton.setFillColor(sf::Color(121, 2, 2));
        m_introButton.setFillColor(sf::Color::Black);
        m_exitButton.setFillColor(sf::Color::Black);
    }
    else if (m_isIntroButtonSelected)
    {
        m_playButton.setFillColor(sf::Color::Black);
        m_rankButton.setFillColor(sf::Color::Black);
        m_introButton.setFillColor(sf::Color(121, 2, 2));
        m_exitButton.setFillColor(sf::Color::Black);
    }
    else if (m_isExitButtonSelected)
    {
        m_playButton.setFillColor(sf::Color::Black);
        m_rankButton.setFillColor(sf::Color::Black);
        m_introButton.setFillColor(sf::Color::Black);
        m_exitButton.setFillColor(sf::Color(121, 2, 2));
    }
    else
    {
        m_playButton.setFillColor(sf::Color::Black);
        m_rankButton.setFillColor(sf::Color::Black);
        m_introButton.setFillColor(sf::Color::Black);
        m_exitButton.setFillColor(sf::Color::Black);
    }

    if(m_isPlayButtonPressed)
    {
        m_context->m_states->PopCurrent();
        m_context->m_states->Add(std::make_unique<Welcome>(m_context), true);
    }
    else if (m_isRankButtonPressed)
    {
        m_context->m_states->PopCurrent();
        m_context->m_states->Add(std::make_unique<Ranking>(m_context), true);
    }
    else if (m_isIntroButtonPressed)
    {
        m_context->m_states->PopCurrent();
        m_context->m_states->Add(std::make_unique<MakeWish>(m_context), true);
    }
    else if(m_isExitButtonPressed)
        m_context->m_window->close();

}

void MainMenu::Draw()
{
    m_context->m_window->clear();
    m_context->m_window->draw(m_bgIamgeDraw);
    m_context->m_window->draw(m_gameTitle);
    m_context->m_window->draw(m_playButton);
    m_context->m_window->draw(m_rankButton);
    m_context->m_window->draw(m_introButton);
    m_context->m_window->draw(m_exitButton);
    m_context->m_window->display();
}