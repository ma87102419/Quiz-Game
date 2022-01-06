#include <SFML/Graphics/CircleShape.hpp>

#include "../include/Game.h"
#include "../include/MainMenu.h"
#include <iostream>


Game::Game() : m_context(std::make_shared<Context>()), m_userInfoFile("assets/Info/user_info_utf8.txt")
{
    m_context->m_window->create(sf::VideoMode(1000, 750, 32), "Quiz Game", sf::Style::Close);
    m_context->m_states->Add(std::make_unique<MainMenu>(m_context));
}

Game::~Game()
{
    // TODO: write m_userInfoVec into file
    std::cout << "Goodbye" << '\n';
}

void Game::Run()
{
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Clock clock;
    sf::Time timeSinceLastFrame = sf::Time::Zero;
    if(m_userInfoFile)
    {
        struct UserInfo tmp_info;
        while(m_userInfoFile >> tmp_info.User >>  tmp_info.Pwd >> tmp_info.CompleteStatus
                >> tmp_info.TotalQuesAnswered >> tmp_info.TimeUsed >> tmp_info.Life
                >> tmp_info.CurrentLv >> tmp_info.AccountStatus >> tmp_info.Wish
                >> tmp_info.WishStatus >> tmp_info.BannedStatus >> tmp_info.BannedTime)
        {
            (*m_context->m_userInfoVec).push_back(tmp_info);
        }
    }
    //for (int i = 0; i < (*m_context->m_userInfoVec).size(); i++)
    //    std::cout << (*m_context->m_userInfoVec)[i].User << '\n';


    while (m_context->m_window->isOpen())
    {
        timeSinceLastFrame += clock.restart();

        while (timeSinceLastFrame > TIME_PER_FRAME)
        {
            timeSinceLastFrame -= TIME_PER_FRAME;

            m_context->m_states->ProcessStateChange();
            m_context->m_states->GetCurrent()->ProcessInput();
            m_context->m_states->GetCurrent()->Update(TIME_PER_FRAME);
            m_context->m_states->GetCurrent()->Draw();
        }
    }
}