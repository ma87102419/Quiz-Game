#include "../include/MainMenu.h"
#include "../include/Login.h"
#include "../include/Register.h"
#include "../include/Welcome.h"

#include <SFML/Window/Event.hpp>
#include <cmath>


Welcome::Welcome(std::shared_ptr<Context> &context)
        : m_context(context),
          m_isLoginButtonSelected(false), m_isLoginButtonPressed(false),
          m_isRegisterButtonSelected(false), m_isRegisterButtonPressed(false),
          m_isReturnMenuButtonSelected(false), m_isReturnMenuButtonPressed(false)
{
}

Welcome::~Welcome()
{
}


bool Welcome::IsTextSelected(sf::Text object)
{
    int obj_x = object.getPosition().x, obj_y = object.getPosition().y;
    int obj_w = object.getGlobalBounds().width, obj_h = object.getGlobalBounds().height;
    sf::Vector2<int> mouse_pos = sf::Mouse::getPosition(*m_context->m_window);
    int mouse_x = mouse_pos.x, mouse_y = mouse_pos.y;
    if (abs(mouse_x - obj_x) <= obj_w / 2 && abs(mouse_y - obj_y) <= obj_h / 2)
        return true;
    else
        return false;
}


bool Welcome::IsTextClicked(sf::Text object, sf::Mouse::Button button)
{
    if (sf::Mouse::isButtonPressed(button) && IsTextSelected(object))
        return true;
    return false;
}


void Welcome::Init()
{
    m_context->m_assets->AddFont(MAIN_FONT, "assets/fonts/NotoSerifTC-Medium.otf");
    // Title
    m_welcomeTitle.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_welcomeTitle.setString("Welcome !");
    m_welcomeTitle.setOrigin(m_welcomeTitle.getLocalBounds().width / 2,
                             m_welcomeTitle.getLocalBounds().height / 2);
    m_welcomeTitle.setPosition(m_context->m_window->getSize().x / 2 - 45.f,
                            m_context->m_window->getSize().y / 2 - 330.f);
    m_welcomeTitle.setCharacterSize(54);

    // Login Button
    m_loginButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_loginButton.setString(L"登入");
    m_loginButton.setOrigin(m_loginButton.getLocalBounds().width / 2,
                           m_loginButton.getLocalBounds().height / 2);
    m_loginButton.setPosition(m_context->m_window->getSize().x / 2,
                             m_context->m_window->getSize().y / 2 - 150.f);
    m_loginButton.setCharacterSize(40);

    // Register Button
    m_registerButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_registerButton.setString(L"註冊");
    m_registerButton.setOrigin(m_registerButton.getLocalBounds().width / 2,
                           m_registerButton.getLocalBounds().height / 2);
    m_registerButton.setPosition(m_context->m_window->getSize().x / 2,
                             m_context->m_window->getSize().y / 2 - 75.f);
    m_registerButton.setCharacterSize(40);

    // Return Menu Button
    m_returnMenuButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_returnMenuButton.setString(L"回到主選單");
    m_returnMenuButton.setOrigin(m_returnMenuButton.getLocalBounds().width / 2,
                            m_returnMenuButton.getLocalBounds().height / 2);
    m_returnMenuButton.setPosition(m_context->m_window->getSize().x / 2,
                              m_context->m_window->getSize().y / 2);
    m_returnMenuButton.setCharacterSize(40);

}


void Welcome::ProcessInput()
{
    sf::Event event;
    while (m_context->m_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_context->m_window->close();
        }

        if (IsTextSelected(m_loginButton))
        {
            m_isLoginButtonSelected = true;
            m_isRegisterButtonSelected = false;
            m_isReturnMenuButtonSelected = false;

        }
        else if (IsTextSelected(m_registerButton))
        {
            m_isLoginButtonSelected = false;
            m_isRegisterButtonSelected = true;
            m_isReturnMenuButtonSelected = false;
        }
        else if (IsTextSelected(m_returnMenuButton))
        {
            m_isLoginButtonSelected = false;
            m_isRegisterButtonSelected = false;
            m_isReturnMenuButtonSelected = true;
        }
        else
        {
            m_isLoginButtonSelected = false;
            m_isRegisterButtonSelected = false;
            m_isReturnMenuButtonSelected = false;
        }

        if (IsTextClicked(m_loginButton, sf::Mouse::Left))
        {
            m_isLoginButtonPressed = true;
            m_isRegisterButtonPressed = false;
            m_isReturnMenuButtonPressed = false;
        }
        else if (IsTextClicked(m_registerButton, sf::Mouse::Left))
        {
            m_isLoginButtonPressed = false;
            m_isRegisterButtonPressed = true;
            m_isReturnMenuButtonPressed = false;
        }
        else if (IsTextClicked(m_returnMenuButton, sf::Mouse::Left))
        {
            m_isLoginButtonPressed = false;
            m_isRegisterButtonPressed = false;
            m_isReturnMenuButtonPressed = true;
        }
        else
        {
            m_isLoginButtonPressed = false;
            m_isRegisterButtonPressed = false;
            m_isReturnMenuButtonPressed = false;
        }


    }
}

void Welcome::Update(sf::Time deltaTime)
{
    if(m_isLoginButtonSelected)
    {
        m_loginButton.setFillColor(sf::Color::Black);
        m_registerButton.setFillColor(sf::Color::White);
        m_returnMenuButton.setFillColor(sf::Color::White);
    }
    else if (m_isRegisterButtonSelected)
    {
        m_loginButton.setFillColor(sf::Color::White);
        m_registerButton.setFillColor(sf::Color::Black);
        m_returnMenuButton.setFillColor(sf::Color::White);
    }
    else if (m_isReturnMenuButtonSelected)
    {
        m_loginButton.setFillColor(sf::Color::White);
        m_registerButton.setFillColor(sf::Color::White);
        m_returnMenuButton.setFillColor(sf::Color::Black);
    }
    else
    {
        m_loginButton.setFillColor(sf::Color::White);
        m_registerButton.setFillColor(sf::Color::White);
        m_returnMenuButton.setFillColor(sf::Color::White);
    }

    if(m_isLoginButtonPressed)
    {
        m_context->m_states->PopCurrent();
        m_context->m_states->Add(std::make_unique<Login>(m_context), true);
    }
    else if (m_isRegisterButtonPressed)
    {
        m_context->m_states->PopCurrent();
        m_context->m_states->Add(std::make_unique<Register>(m_context), true);
    }
    else if (m_isReturnMenuButtonPressed)
    {
        m_context->m_states->PopCurrent();
        m_context->m_states->Add(std::make_unique<MainMenu>(m_context), true);
    }

}

void Welcome::Draw()
{
    m_context->m_window->clear(sf::Color(102, 178, 255));
    m_context->m_window->draw(m_welcomeTitle);
    m_context->m_window->draw(m_loginButton);
    m_context->m_window->draw(m_registerButton);
    m_context->m_window->draw(m_returnMenuButton);
    m_context->m_window->display();
}