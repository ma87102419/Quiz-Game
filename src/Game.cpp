#include <SFML/Graphics/CircleShape.hpp>
#include <typeinfo>
#include <regex>

#include "../include/Game.h"
#include "../include/MainMenu.h"
#include "../include/MakeWish.h"
#include <iostream>


std::string Game::replaceAll(std::string str, const std::string from, const std::string to) {
    if(from.empty())
        return str;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
    return str;
}

std::string Game::enc_spaces(std::string s)
{
    return replaceAll(s, " ", "|");
}

std::string Game::dec_spaces(std::string s)
{
    return replaceAll(s, "|", " ");
}


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
        OutputFile << enc_spaces(tmp_info.User) << ' ' 
                   << enc_spaces(tmp_info.Pwd) << ' '
                   << tmp_info.CompleteStatus << ' '
                   << tmp_info.TotalQuesAnswered << ' '
                   << tmp_info.TimeUsed << ' '
                   << tmp_info.Life << ' '
                   << tmp_info.CurrentLv << ' '
                   << tmp_info.AccountStatus << ' '
                   << enc_spaces(tmp_info.Wish) << ' '
                   << tmp_info.WishStatus << ' '
                   << tmp_info.BannedStatus << ' '
                   << tmp_info.BannedTime << '\n';
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

    sf::Image icon;
    icon.loadFromFile("assets/textures/window_icon.jpg");
    m_context->m_window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    std::ifstream InputFile;
    InputFile.open(m_UserInfoFileName);
    if(InputFile)
    {
        struct UserInfo tmp_info;
        while(InputFile >> tmp_info.User
                        >> tmp_info.Pwd
                        >> tmp_info.CompleteStatus 
                        >> tmp_info.TotalQuesAnswered 
                        >> tmp_info.TimeUsed 
                        >> tmp_info.Life
                        >> tmp_info.CurrentLv 
                        >> tmp_info.AccountStatus 
                        >> tmp_info.Wish
                        >> tmp_info.WishStatus 
                        >> tmp_info.BannedStatus 
                        >> tmp_info.BannedTime)
        {
            tmp_info.User = dec_spaces(tmp_info.User);
            tmp_info.Pwd = dec_spaces(tmp_info.Pwd);
            tmp_info.Wish = dec_spaces(tmp_info.Wish);
            (*m_context->m_userInfoVec).push_back(tmp_info);
        }
    }
    std::cout << (*m_context->m_userInfoVec).size() << '\n';
    //for (int i = 0; i < (*m_context->m_userInfoVec).size(); i++)
    //    std::cout << (*m_context->m_userInfoVec)[i].User << '\n';

    if (!bgMusic.openFromFile("assets/music/NTU_song.ogg"))
        std::cout << "ERROR" << '\n';

    if (!wishMusic.openFromFile("assets/music/wish.ogg"))
        std::cout << "ERROR" << '\n';

    while (m_context->m_window->isOpen())
    {
        timeSinceLastFrame += clock.restart();

        while (timeSinceLastFrame > TIME_PER_FRAME)
        {
            timeSinceLastFrame -= TIME_PER_FRAME;

            m_context->m_states->ProcessStateChange();
            if (typeid(*m_context->m_states->GetCurrent()) == typeid(MakeWish)
                && wishMusic.getStatus() != sf::Music::Playing)
            {
                bgMusic.stop();
                wishMusic.setVolume(30.f);
                wishMusic.setPlayingOffset(sf::seconds(2.0f));
                wishMusic.setLoop(true);
                wishMusic.play();
            }
            else if (typeid(*m_context->m_states->GetCurrent()) != typeid(MakeWish)
                    && bgMusic.getStatus() != sf::Music::Playing)
            {
                wishMusic.stop();
                bgMusic.setVolume(30.f);
                bgMusic.setPlayingOffset(sf::seconds(25.5f));
                bgMusic.setLoop(true);
                bgMusic.play();
            }
            m_context->m_states->GetCurrent()->ProcessInput();
            m_context->m_states->GetCurrent()->Update(TIME_PER_FRAME);
            m_context->m_states->GetCurrent()->Draw();
        }
    }
}