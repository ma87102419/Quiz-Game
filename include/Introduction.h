#pragma once

#include <memory>

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>

#include "State.h"
#include "Game.h"



class Introduction : public Engine::State
{
private:
    std::shared_ptr<Context> m_context;
    sf::Text m_introTitle;
    sf::Text m_returnMenuButton;
    //sf::Text m_firstLine;
    sf::Texture m_bgImage; // background image
    sf::Sprite m_bgIamgeDraw; // texture to sprite

    bool m_isReturnMenuButtonSelected;
    bool m_isReturnMenuButtonPressed;

    bool IsTextSelected(sf::Text object);
    bool IsTextClicked(sf::Text object, sf::Mouse::Button button);

public:
    Introduction(std::shared_ptr<Context> &context);
    ~Introduction();

    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltaTime) override;
    void Draw() override;
};