#include "../include/GameOver.h"
#include "../include/MainMenu.h"
#include <iostream>
#include <SFML/Window/Event.hpp>

GameOver::GameOver(std::shared_ptr<Context> &context)
        : m_context(context), m_isReturnMenuButtonSelected(false),
          m_isReturnMenuButtonPressed(false), m_isExitButtonSelected(false),
          m_isExitButtonPressed(false)
{
}

GameOver::~GameOver()
{
}

bool GameOver::IsTextSelected(sf::Text object)
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


bool GameOver::IsTextClicked(sf::Text object, sf::Mouse::Button button)
{
    if (sf::Mouse::isButtonPressed(button) && IsTextSelected(object))
        return true;
    return false;
}


void GameOver::Init()
{
    m_context->m_assets->AddFont(MAIN_FONT, "assets/fonts/NotoSerifTC-Medium.otf");
    // Title
    m_gameOverTitle.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_gameOverTitle.setFillColor(sf::Color::Black);
    m_gameOverTitle.setString(L"遊戲結束");
    m_gameOverTitle.setOrigin(m_gameOverTitle.getLocalBounds().width / 2,
                              m_gameOverTitle.getLocalBounds().height / 2);
    m_gameOverTitle.setPosition(m_context->m_window->getSize().x / 2 - 80.f,
                                m_context->m_window->getSize().y / 2 - 530.f);
    m_gameOverTitle.setCharacterSize(84);

    // Return Menu Button
    m_returnMenuButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_returnMenuButton.setString(L"登出並回到主選單");
    m_returnMenuButton.setOrigin(m_returnMenuButton.getLocalBounds().width / 2,
                                 m_returnMenuButton.getLocalBounds().height / 2);
    m_returnMenuButton.setPosition(m_context->m_window->getSize().x / 2 - 70.f,
                              m_context->m_window->getSize().y / 2 - 250.f);
    m_returnMenuButton.setCharacterSize(64);

    // Exit Button
    m_exitButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_exitButton.setString(L"退出遊戲");
    m_exitButton.setOrigin(m_exitButton.getLocalBounds().width / 2,
                           m_exitButton.getLocalBounds().height / 2);
    m_exitButton.setPosition(m_context->m_window->getSize().x / 2 - 30.f,
                             m_context->m_window->getSize().y / 2 - 100.f);
    m_exitButton.setCharacterSize(64);

    // load image
    if (!m_bgImage.loadFromFile("assets/background/original_light_new.jpg"))// background image
        std::cout << "no data exists!";
    m_bgImageDraw.setTexture(m_bgImage);
}

void GameOver::ProcessInput()
{
    sf::Event event;
    while (m_context->m_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_context->m_window->close();
        }
        if (IsTextSelected(m_returnMenuButton))
        {
            m_isReturnMenuButtonSelected = true;
            m_isExitButtonSelected = false;
        }
        else if (IsTextSelected(m_exitButton))
        {
            m_isReturnMenuButtonSelected = false;
            m_isExitButtonSelected = true;
        }
        else
        {
            m_isReturnMenuButtonSelected = false;
            m_isExitButtonSelected = false;
        }
        if (IsTextClicked(m_returnMenuButton, sf::Mouse::Left))
        {
            m_isReturnMenuButtonPressed = true;
            m_isExitButtonPressed = false;
        }
        else if (IsTextClicked(m_exitButton, sf::Mouse::Left))
        {
            m_isReturnMenuButtonPressed = false;
            m_isExitButtonPressed = true;
        }
        else
        {
            m_isReturnMenuButtonPressed = false;
            m_isExitButtonPressed = false;
        }
    }
}

void GameOver::Update(sf::Time deltaTime)
{
    if (m_isReturnMenuButtonSelected)
    {
        m_returnMenuButton.setFillColor(sf::Color(121,2,2));
        m_exitButton.setFillColor(sf::Color::Black);
    }
    else if (m_isExitButtonSelected)
    {
        m_exitButton.setFillColor(sf::Color(121,2,2));
        m_returnMenuButton.setFillColor(sf::Color::Black);
    }
    else
    {
       m_exitButton.setFillColor(sf::Color::Black);
       m_returnMenuButton.setFillColor(sf::Color::Black); 
    }

    if (m_isReturnMenuButtonPressed)
    {
        m_context->m_states->PopCurrent();
        m_context->m_states->Add(std::make_unique<MainMenu>(m_context), true);
    }
    else if (m_isExitButtonPressed)
    {
        m_context->m_window->close();
    }
}

void GameOver::Draw()
{
    m_context->m_window->clear();
    m_context->m_window->draw(m_bgImageDraw);
    m_context->m_window->draw(m_gameOverTitle);
    m_context->m_window->draw(m_returnMenuButton);
    m_context->m_window->draw(m_exitButton);
    m_context->m_window->display();
}