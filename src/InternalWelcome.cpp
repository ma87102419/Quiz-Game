#include "../include/InternalWelcome.h"
#include "../include/MainMenu.h"
#include "../include/Welcome.h"
#include "../include/PlayerInfo.h"
#include "../include/GamePlay.h"


#include <SFML/Window/Event.hpp>


InternalWelcome::InternalWelcome(std::shared_ptr<Context> &context)
        : m_context(context),
          m_isStartButtonSelected(false), m_isStartButtonPressed(false), 
          m_isPlayerInfoButtonSelected(false), m_isPlayerInfoButtonPressed(false),
          m_isLogoutButtonSelected(false), m_isLogoutButtonPressed(false), showBannedMsg(false)
{
}

InternalWelcome::~InternalWelcome()
{
}

bool InternalWelcome::IsTextSelected(sf::Text object)
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


bool InternalWelcome::IsTextClicked(sf::Text object, sf::Mouse::Button button)
{
    if (sf::Mouse::isButtonPressed(button) && IsTextSelected(object))
        return true;
    return false;
}


void InternalWelcome::Init()
{
    m_context->m_assets->AddFont(MAIN_FONT, "assets/fonts/NotoSerifTC-Medium.otf");
    // Welcome user
    std::cout << (*m_context->m_userInfoVec)[*m_context->m_currUserindex].User << '\n';
    m_internalWelcomeTitle.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_internalWelcomeTitle.setString("Welcome " + (*m_context->m_userInfoVec)[*m_context->m_currUserindex].User + " !");
    m_internalWelcomeTitle.setOrigin(m_internalWelcomeTitle.getLocalBounds().width / 2,
                                     m_internalWelcomeTitle.getLocalBounds().height / 2);
    m_internalWelcomeTitle.setPosition(m_context->m_window->getSize().x / 2 - 80.f,
                              m_context->m_window->getSize().y / 2 - 530.f);
    m_internalWelcomeTitle.setCharacterSize(84);

    // Buttons
    m_startButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_startButton.setString(L"????????????");
    m_startButton.setOrigin(m_startButton.getLocalBounds().width / 2,
                            m_startButton.getLocalBounds().height / 2);
    m_startButton.setPosition(m_context->m_window->getSize().x / 2 - 30.f,
                              m_context->m_window->getSize().y / 2 - 250.f);
    m_startButton.setCharacterSize(64);

    m_playerInfoButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_playerInfoButton.setString(L"????????????");
    m_playerInfoButton.setOrigin(m_playerInfoButton.getLocalBounds().width / 2,
                                 m_playerInfoButton.getLocalBounds().height / 2);
    m_playerInfoButton.setPosition(m_context->m_window->getSize().x / 2 - 30.f,
                             m_context->m_window->getSize().y / 2 - 100.f);
    m_playerInfoButton.setCharacterSize(64);

    m_logoutButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_logoutButton.setString(L"??????");
    m_logoutButton.setOrigin(m_logoutButton.getLocalBounds().width / 2,
                             m_logoutButton.getLocalBounds().height / 2);
    m_logoutButton.setPosition(m_context->m_window->getSize().x / 2 - 30.f,
                                   m_context->m_window->getSize().y / 2 + 50.f);
    m_logoutButton.setCharacterSize(64);

    // error message
    m_bannedMsg.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    //m_bannedMsg.setString(L"?????????????????????");
    m_bannedMsg.setFillColor(sf::Color::Red);
    m_bannedMsg.setOrigin(m_logoutButton.getLocalBounds().width / 2,
        m_logoutButton.getLocalBounds().height / 2);
    m_bannedMsg.setPosition(m_context->m_window->getSize().x / 2,
        m_context->m_window->getSize().y / 2 + 80.f);
    m_bannedMsg.setCharacterSize(40);

    // ntu emblem draw
    if (!m_ntuEmblem.loadFromFile("assets/background/Emblem72.png"))// background image
        std::cout << "no data exists!";
    m_ntuEmblemDraw.setTexture(m_ntuEmblem);
    m_ntuEmblemDraw.setPosition(m_context->m_window->getSize().x / 2 - 960.f,                m_context->m_window->getSize().y / 2 - 530.f);

}

void InternalWelcome::ProcessInput()
{
    sf::Event event;
    while (m_context->m_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_context->m_window->close();
        }

        if (IsTextSelected(m_startButton))
        {
            m_isStartButtonSelected = true;
            m_isPlayerInfoButtonSelected = false;
            m_isLogoutButtonSelected = false;
        }
        else if (IsTextSelected(m_playerInfoButton))
        {
            m_isStartButtonSelected = false;
            m_isPlayerInfoButtonSelected = true;
            m_isLogoutButtonSelected = false;
        }
        else if (IsTextSelected(m_logoutButton))
        {
            m_isStartButtonSelected = false;
            m_isPlayerInfoButtonSelected = false;
            m_isLogoutButtonSelected = true;
        }
        else
        {
            m_isStartButtonSelected = false;
            m_isPlayerInfoButtonSelected = false;
            m_isLogoutButtonSelected = false;
        }

        if (IsTextClicked(m_startButton, sf::Mouse::Left))
        {
            m_isStartButtonPressed = true;
            m_isPlayerInfoButtonPressed = false;
            m_isLogoutButtonPressed = false;
        }
        else if (IsTextClicked(m_playerInfoButton, sf::Mouse::Left))
        {
            m_isStartButtonPressed = false;
            m_isPlayerInfoButtonPressed = true;
            m_isLogoutButtonPressed = false;
        }
        else if (IsTextClicked(m_logoutButton, sf::Mouse::Left))
        {
            m_isStartButtonPressed = false;
            m_isPlayerInfoButtonPressed = false;
            m_isLogoutButtonPressed = true;
        }
        else
        {
            m_isStartButtonPressed = false;
            m_isPlayerInfoButtonPressed = false;
            m_isLogoutButtonPressed = false;
        }
    }
}

void InternalWelcome::Update(sf::Time deltaTime)
{
    if (m_isStartButtonSelected)
    {
        m_startButton.setFillColor(sf::Color::Black);
        m_playerInfoButton.setFillColor(sf::Color::White);
        m_logoutButton.setFillColor(sf::Color::White);
    }
    else if (m_isPlayerInfoButtonSelected)
    {
        m_startButton.setFillColor(sf::Color::White);
        m_playerInfoButton.setFillColor(sf::Color::Black);
        m_logoutButton.setFillColor(sf::Color::White);
    }
    else if (m_isLogoutButtonSelected)
    {
        m_startButton.setFillColor(sf::Color::White);
        m_playerInfoButton.setFillColor(sf::Color::White);
        m_logoutButton.setFillColor(sf::Color::Black);
    }
    else
    {
        m_startButton.setFillColor(sf::Color::White);
        m_playerInfoButton.setFillColor(sf::Color::White);
        m_logoutButton.setFillColor(sf::Color::White);
    }

    if (m_isStartButtonPressed)
    {
        // add the condition a user can;t login the game
        if ((*m_context->m_userInfoVec)[*m_context->m_currUserindex].BannedStatus &&
            time(nullptr) - (*m_context->m_userInfoVec)[*m_context->m_currUserindex].BannedTime < 30) // TODO: make it a memebr variable
        {
            showBannedMsg = true;
            sf::String bannedText = L"??? ";
            bannedText += std::to_string(30 - (time(nullptr) - (*m_context->m_userInfoVec)[*m_context->m_currUserindex].BannedTime));
            bannedText += L" ???????????????????????????";

            m_bannedMsg.setString(bannedText);

        }
        else
        {
            showBannedMsg = false;
            (*m_context->m_userInfoVec)[*m_context->m_currUserindex].BannedStatus = false;
            (*m_context->m_userInfoVec)[*m_context->m_currUserindex].BannedTime = 0;
            (*m_context->m_userInfoVec)[*m_context->m_currUserindex].TimeUsed = 0;
            m_context->m_states->PopCurrent();
            m_context->m_states->Add(std::make_unique<GamePlay>(m_context));
        }
    }
    else if (m_isPlayerInfoButtonPressed)
    {
        m_context->m_states->PopCurrent();
        m_context->m_states->Add(std::make_unique<PlayerInfo>(m_context));
    }
    else if (m_isLogoutButtonPressed) // TODO &&...check valid user
    {
        m_context->m_states->PopCurrent();
        m_context->m_states->Add(std::make_unique<InternalWelcome>(m_context));
    }

}

void InternalWelcome::Draw()
{
    m_context->m_window->clear(sf::Color(102, 178, 255));
    m_context->m_window->draw(m_internalWelcomeTitle);
    m_context->m_window->draw(m_startButton);
    m_context->m_window->draw(m_playerInfoButton);
    m_context->m_window->draw(m_ntuEmblemDraw);
    m_context->m_window->draw(m_logoutButton);
    if(showBannedMsg == true)
        m_context->m_window->draw(m_bannedMsg);
    m_context->m_window->display();
}

