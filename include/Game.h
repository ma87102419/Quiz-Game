#pragma once

#include <memory>

#include <SFML/Graphics/RenderWindow.hpp>

#include "AssetMan.h"
#include "StateMan.h"



enum AssetID
{
    MAIN_FONT = 0,
};

struct Context
{
    std::unique_ptr<Engine::AssetMan> m_assets;
    std::unique_ptr<Engine::StateMan> m_states;
    std::unique_ptr<sf::RenderWindow> m_window;
    std::unique_ptr<std::string> m_currUser;
    std::unique_ptr<std::string> m_currUserpwd;
    std::unique_ptr<int> m_currUserindex;


    Context()
    {
        m_assets = std::make_unique<Engine::AssetMan>();
        m_states = std::make_unique<Engine::StateMan>();
        m_window = std::make_unique<sf::RenderWindow>();
        m_currUser = std::make_unique<std::string>();
        m_currUserpwd = std::make_unique<std::string>();
        m_currUserindex = std::make_unique<int>();
    }
};

class Game
{
private:
    std::shared_ptr<Context> m_context;
    const sf::Time TIME_PER_FRAME = sf::seconds(1.f/60.f);

public:
    Game();
    ~Game();

    void Run();
};