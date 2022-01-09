#pragma once

#include <memory>

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>

#include "State.h"
#include "Game.h"



class Ranking : public Engine::State
{
private:
    std::shared_ptr<Context> m_context;
    sf::Text m_rankingTitle;
    sf::Text m_returnMenuButton;
    sf::Texture m_bgImage; // background image
    sf::Sprite m_bgIamgeDraw; // texture to sprite

    bool m_isReturnMenuButtonSelected;
    bool m_isReturnMenuButtonPressed;

    bool IsTextSelected(sf::Text object);
    bool IsTextClicked(sf::Text object, sf::Mouse::Button button);

public:
    Ranking(std::shared_ptr<Context> &context);
    ~Ranking();

    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltaTime) override;
    void Draw() override;
};