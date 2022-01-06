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



class MakeWish : public Engine::State
{
private:
    std::shared_ptr<Context> m_context;
    sf::Text m_makeWishTitle;
    sf::Text m_submitButton;
    sf::Text m_wishText;

    sf::Sprite m_prof;

    bool m_isSubmitButtonSelected;
    bool m_isSubmitButtonPressed;

    bool m_isWishBoxSelected;
    bool m_isWishBoxPressed;

    sf::RectangleShape m_wishBox;

    void InputLogic(int charTyped, std::string &s);

    std::string m_wish;

    bool IsTextSelected(sf::Text object);
    bool IsTextClicked(sf::Text object, sf::Mouse::Button button);

    bool IsBoxSelected(sf::RectangleShape object);
    bool IsBoxClicked(sf::RectangleShape object, sf::Mouse::Button button);

public:
    MakeWish(std::shared_ptr<Context> &context);
    ~MakeWish();

    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltaTime) override;
    void Draw() override;
};