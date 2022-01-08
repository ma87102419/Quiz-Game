#pragma once

#include <memory>

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>

#include "State.h"
#include "Game.h"
#include "GamePlay.h"



class MainMenu : public Engine::State
{
private:
    std::shared_ptr<Context> m_context;
    sf::Text m_gameTitle;
    sf::Text m_playButton;
    sf::Text m_rankButton;
    sf::Text m_introButton;
    sf::Text m_exitButton;
    // sf texture
    sf::Texture m_bgImage; // background image
    sf::Sprite m_bgIamgeDraw; // texture to sprite

    bool m_isPlayButtonSelected;
    bool m_isPlayButtonPressed;

    bool m_isRankButtonSelected;
    bool m_isRankButtonPressed;

    bool m_isIntroButtonSelected;
    bool m_isIntroButtonPressed;

    bool m_isExitButtonSelected;
    bool m_isExitButtonPressed;

    bool IsTextSelected(sf::Text object);
    bool IsTextClicked(sf::Text object, sf::Mouse::Button button);

public:
    MainMenu(std::shared_ptr<Context> &context);
    ~MainMenu();

    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltaTime) override;
    void Draw() override;
};