#include "../include/Ranking.h"
#include "../include/MainMenu.h"
#include<iostream>
#include <SFML/Window/Event.hpp>

Ranking::Ranking(std::shared_ptr<Context> &context)
        : m_context(context),
          m_isReturnMenuButtonSelected(false), m_isReturnMenuButtonPressed(false)
{
}

Ranking::~Ranking()
{
}

bool Ranking::IsTextSelected(sf::Text object)
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


bool Ranking::IsTextClicked(sf::Text object, sf::Mouse::Button button)
{
    if (sf::Mouse::isButtonPressed(button) && IsTextSelected(object))
        return true;
    return false;
}

void Ranking::Init()
{
    // Title
    m_rankingTitle.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_rankingTitle.setString(L"願望清單");
    m_rankingTitle.setFillColor(sf::Color::Black);
    m_rankingTitle.setOrigin(m_rankingTitle.getLocalBounds().width / 2,
                             m_rankingTitle.getLocalBounds().height / 2);
    m_rankingTitle.setPosition(m_context->m_window->getSize().x / 2,
                             m_context->m_window->getSize().y / 2 - 100.f);
    // Buttons
    m_returnMenuButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_returnMenuButton.setString(L"回到主選單");
    m_returnMenuButton.setFillColor(sf::Color::Black);
    m_returnMenuButton.setOrigin(m_returnMenuButton.getLocalBounds().width / 2,
                                 m_returnMenuButton.getLocalBounds().height / 2);
    m_returnMenuButton.setPosition(m_context->m_window->getSize().x / 2,
                                   m_context->m_window->getSize().y / 2 + 50.f);

    // load texture and sprite
    if (!m_bgImage.loadFromFile("assets/background/original_light_new.jpg"))// background image
        std::cout << "no data exists!";
    m_bgIamgeDraw.setTexture(m_bgImage);

}

void Ranking::ProcessInput()
{
    sf::Event event;
    while (m_context->m_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_context->m_window->close();
        }

        if (IsTextSelected(m_returnMenuButton))
            m_isReturnMenuButtonSelected = true;
        else
            m_isReturnMenuButtonSelected = false;

        if (IsTextClicked(m_returnMenuButton, sf::Mouse::Left))
            m_isReturnMenuButtonPressed = true;
        else
            m_isReturnMenuButtonPressed = false;
    }
}

void Ranking::Update(sf::Time deltaTime)
{
    if (m_isReturnMenuButtonSelected)
        m_returnMenuButton.setFillColor(sf::Color(121, 2, 2));
    else
    {
        m_returnMenuButton.setFillColor(sf::Color::Black);
    }

    if (m_isReturnMenuButtonPressed)
    {
        m_context->m_states->PopCurrent();
        m_context->m_states->Add(std::make_unique<MainMenu>(m_context));
    }
}

void Ranking::Draw()
{
    m_context->m_window->clear();
    m_context->m_window->draw(m_bgIamgeDraw);
    m_context->m_window->draw(m_rankingTitle);
    m_context->m_window->draw(m_returnMenuButton);
    m_context->m_window->display();
}

