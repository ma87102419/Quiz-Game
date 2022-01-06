#pragma once

#include <memory>
#include <iostream>
#include <sstream>

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>

#include "State.h"
#include "Game.h"

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27
#define SPACE_KEY 32

class InternalWelcome : public Engine::State
{
private:
    std::shared_ptr<Context> m_context;
    sf::Text m_internalWelcomeTitle;
    sf::Text m_startButton;
    sf::Text m_playerInfoButton;
    sf::Text m_logoutButton;
    sf::Text m_welcomeUser;

    bool m_isStartButtonSelected;
    bool m_isStartButtonPressed;

    bool m_isPlayerInfoButtonSelected;
    bool m_isPlayerInfoButtonPressed;

    bool m_isLogoutButtonSelected;
    bool m_isLogoutButtonPressed;

    bool IsTextSelected(sf::Text object);
    bool IsTextClicked(sf::Text object, sf::Mouse::Button button);

    bool IsBoxSelected(sf::RectangleShape object);
    bool IsBoxClicked(sf::RectangleShape object, sf::Mouse::Button button);

public:
    InternalWelcome(std::shared_ptr<Context> &context);
    ~InternalWelcome();

    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltaTime) override;
    void Draw() override;
};