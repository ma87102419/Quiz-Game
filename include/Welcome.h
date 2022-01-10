#pragma once

#include <memory>

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>

#include "State.h"



class Welcome : public Engine::State
{
private:
    std::shared_ptr<Context> m_context;
    sf::Text m_welcomeTitle;
    sf::Text m_loginButton;
    sf::Text m_registerButton;
    sf::Text m_returnMenuButton;

    sf::Texture m_ntuEmblem; // background image
    sf::Sprite m_ntuEmblemDraw; // texture to sprite

    bool m_isLoginButtonSelected;
    bool m_isLoginButtonPressed;

    bool m_isRegisterButtonSelected;
    bool m_isRegisterButtonPressed;

    bool m_isReturnMenuButtonSelected;
    bool m_isReturnMenuButtonPressed;


    bool IsTextSelected(sf::Text object);
    bool IsTextClicked(sf::Text object, sf::Mouse::Button button);

public:
    Welcome(std::shared_ptr<Context> &context);
    ~Welcome();

    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltaTime) override;
    void Draw() override;
};