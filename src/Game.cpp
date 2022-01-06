#include <SFML/Graphics/CircleShape.hpp>

#include "../include/Game.h"
#include "../include/MainMenu.h"
#include <iostream>


Game::Game() : m_context(std::make_shared<Context>()), m_UserInfoFileName("assets/Info/user_info_utf8.txt")
{
    m_context->m_window->create(sf::VideoMode(1440, 800, 32), "Quiz Game", sf::Style::Close);
    m_context->m_states->Add(std::make_unique<MainMenu>(m_context));
}

Game::~Game()
{
    std::cout << (*m_context->m_userInfoVec).size() << '\n';

    std::ofstream OutputFile;
    OutputFile.open(m_UserInfoFileName);
    for (int i = 0; i < (*m_context->m_userInfoVec).size(); i++)
    {
        struct UserInfo tmp_info = (*m_context->m_userInfoVec)[i];
        OutputFile << tmp_info.User << ' ' << tmp_info.Pwd << ' ' << tmp_info.CompleteStatus << ' '
                   << tmp_info.TotalQuesAnswered << ' ' << tmp_info.TimeUsed << ' ' << tmp_info.Life << ' '
                   << tmp_info.CurrentLv << ' ' << tmp_info.AccountStatus << ' ' << tmp_info.Wish << ' '
                   << tmp_info.WishStatus << ' ' << tmp_info.BannedStatus << ' ' << tmp_info.BannedTime << '\n';
    }
    OutputFile.close();

    std::cout << "Goodbye" << '\n';

}

void Game::Run()
{
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Clock clock;
    sf::Time timeSinceLastFrame = sf::Time::Zero;

    std::ifstream InputFile;
    InputFile.open(m_UserInfoFileName);
    if(InputFile)
    {
        struct UserInfo tmp_info;
        while(InputFile >> tmp_info.User >>  tmp_info.Pwd >> tmp_info.CompleteStatus
                >> tmp_info.TotalQuesAnswered >> tmp_info.TimeUsed >> tmp_info.Life
                >> tmp_info.CurrentLv >> tmp_info.AccountStatus >> tmp_info.Wish
                >> tmp_info.WishStatus >> tmp_info.BannedStatus >> tmp_info.BannedTime)
        {
            (*m_context->m_userInfoVec).push_back(tmp_info);
        }
    }
    std::cout << (*m_context->m_userInfoVec).size() << '\n';
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