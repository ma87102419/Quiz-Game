#pragma once

#include <memory>

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>

#include "State.h"
#include "Game.h"



class PlayerInfo : public Engine::State
{
private:
    std::shared_ptr<Context> m_context;
    sf::Text m_playerInfoTitle;
    sf::Text m_nameText;
    sf::Text m_totalQuesAnswered;
    sf::Text m_timeUsed;
    sf::Text m_completeStatus;
    sf::Text m_currLevel;
    sf::Text m_bannedTime;
    sf::Text m_nameTextIcon;
    sf::Text m_totalQuesAnsweredIcon;
    sf::Text m_timeUsedIcon;
    sf::Text m_completeStatusIcon;
    sf::Text m_currLevelIcon;
    sf::Text m_returnMenuButton;
    sf::Texture m_bgImage; // background image
    sf::Sprite m_bgImageDraw; // texture to sprite

    bool m_isReturnMenuButtonSelected;
    bool m_isReturnMenuButtonPressed;

    bool IsTextSelected(sf::Text object);
    bool IsTextClicked(sf::Text object, sf::Mouse::Button button);

public:
    PlayerInfo(std::shared_ptr<Context> &context);
    ~PlayerInfo();

    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltaTime) override;
    void Draw() override;
};