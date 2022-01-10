#include "../include/PauseGame.h"
#include "../include/MainMenu.h"

#include <SFML/Window/Event.hpp>

PauseGame::PauseGame(std::shared_ptr<Context> &context)
        : m_context(context),
          m_isContinueButtonSelected(false), m_isContinueButtonPressed(false),
          m_isReturnMenuButtonSelected(false), m_isReturnMenuButtonPressed(false)
{
}

PauseGame::~PauseGame()
{
}

bool PauseGame::IsTextSelected(sf::Text object)
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


bool PauseGame::IsTextClicked(sf::Text object, sf::Mouse::Button button)
{
    if (sf::Mouse::isButtonPressed(button) && IsTextSelected(object))
        return true;
    return false;
}

void PauseGame::Init()
{
    // Title
    m_pauseTitle.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_pauseTitle.setString(L"遊戲暫停");
    m_pauseTitle.setOrigin(m_pauseTitle.getLocalBounds().width / 2,
                           m_pauseTitle.getLocalBounds().height / 2);
    m_pauseTitle.setPosition(m_context->m_window->getSize().x / 2 - 45.f,
                             m_context->m_window->getSize().y / 2 - 330.f);
    m_pauseTitle.setCharacterSize(54);
    // Buttons
    m_continueButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_continueButton.setString(L"繼續遊戲");
    m_continueButton.setOrigin(m_continueButton.getLocalBounds().width / 2,
                           m_pauseTitle.getLocalBounds().height / 2);
    m_continueButton.setPosition(m_context->m_window->getSize().x / 2 - 20.f,
                             m_context->m_window->getSize().y / 2 - 150.f);
    m_continueButton.setCharacterSize(40);

    m_returnMenuButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_returnMenuButton.setString(L"登出並返回主選單");
    m_returnMenuButton.setOrigin(m_returnMenuButton.getLocalBounds().width / 2,
                                 m_returnMenuButton.getLocalBounds().height / 2);
    m_returnMenuButton.setPosition(m_context->m_window->getSize().x / 2 - 45.f,
                                 m_context->m_window->getSize().y / 2 - 75.f);
    m_returnMenuButton.setCharacterSize(40);


}

void PauseGame::ProcessInput()
{
    sf::Event event;
    while (m_context->m_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_context->m_window->close();
        }

        if (IsTextSelected(m_continueButton))
        {
            m_isContinueButtonSelected = true;
            m_isReturnMenuButtonSelected = false;

        }
        else if (IsTextSelected(m_returnMenuButton))
        {
            m_isContinueButtonSelected = false;
            m_isReturnMenuButtonSelected = true;
        }
        else
        {
            m_isContinueButtonSelected = false;
            m_isReturnMenuButtonSelected = false;
        }

        if (IsTextClicked(m_continueButton, sf::Mouse::Left))
        {
            m_isContinueButtonPressed = true;
            m_isReturnMenuButtonPressed = false;
        }
        else if (IsTextClicked(m_returnMenuButton, sf::Mouse::Left))
        {
            m_isContinueButtonPressed = false;
            m_isReturnMenuButtonPressed = true;
        }
        else
        {
            m_isContinueButtonPressed = false;
            m_isReturnMenuButtonPressed = false;
        }
    }
}

void PauseGame::Update(sf::Time deltaTime)
{
    if (m_isContinueButtonSelected)
    {
        m_continueButton.setFillColor(sf::Color(121, 2, 2));
        m_returnMenuButton.setFillColor(sf::Color::White);
    }
    else if (m_isReturnMenuButtonSelected)
    {
        m_continueButton.setFillColor(sf::Color::White);
        m_returnMenuButton.setFillColor(sf::Color(121, 2, 2));
    }
    else
    {
        m_continueButton.setFillColor(sf::Color::White);
        m_returnMenuButton.setFillColor(sf::Color::White);
    }

    if (m_isContinueButtonPressed)
        m_context->m_states->PopCurrent();
    else if (m_isReturnMenuButtonPressed)
    {
        *m_context->m_currUserindex = -1;
        m_context->m_states->PopCurrent();
        m_context->m_states->Add(std::make_unique<MainMenu>(m_context));
    }
}

void PauseGame::Draw()
{
    m_context->m_window->clear(sf::Color::Black);
    m_context->m_window->draw(m_pauseTitle);
    m_context->m_window->draw(m_continueButton);
    m_context->m_window->draw(m_returnMenuButton);
    m_context->m_window->display();
}