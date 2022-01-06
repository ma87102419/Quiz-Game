#pragma once

#include <memory>
#include <vector>
#include <fstream>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>

#include "AssetMan.h"
#include "StateMan.h"



enum AssetID
{
    MAIN_FONT = 0,
};

struct UserInfo
{
    std::string User;
    std::string Pwd;
    bool CompleteStatus;
    int TotalQuesAnswered;
    int TimeUsed;
    int Life;
    int CurrentLv;
    bool AccountStatus;
    std::string Wish;
    bool WishStatus;
    bool BannedStatus;
    int BannedTime;
};

struct Context
{
    std::unique_ptr<Engine::AssetMan> m_assets;
    std::unique_ptr<Engine::StateMan> m_states;
    std::unique_ptr<sf::RenderWindow> m_window;
    std::unique_ptr<int> m_currUserindex;
    std::unique_ptr<std::vector<UserInfo>>m_userInfoVec;


    Context()
    {
        m_assets = std::make_unique<Engine::AssetMan>();
        m_states = std::make_unique<Engine::StateMan>();
        m_window = std::make_unique<sf::RenderWindow>();
        m_currUserindex = std::make_unique<int>();
        m_userInfoVec = std::make_unique<std::vector<UserInfo>>();

    }
};

class Game
{
private:
    std::shared_ptr<Context> m_context;
    std::ifstream m_userInfoFile;
    const sf::Time TIME_PER_FRAME = sf::seconds(1.f/60.f);

public:
    Game();
    ~Game();

    void Run();
};