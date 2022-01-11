#include "../include/PlayerInfo.h"
#include "../include/InternalWelcome.h"
#include<iostream>
#include <SFML/Window/Event.hpp>

PlayerInfo::PlayerInfo(std::shared_ptr<Context> &context)
        : m_context(context),
          m_isReturnMenuButtonSelected(false), m_isReturnMenuButtonPressed(false)
{
}

PlayerInfo::~PlayerInfo()
{
}

bool PlayerInfo::IsTextSelected(sf::Text object)
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


bool PlayerInfo::IsTextClicked(sf::Text object, sf::Mouse::Button button)
{
    if (sf::Mouse::isButtonPressed(button) && IsTextSelected(object))
        return true;
    return false;
}

void PlayerInfo::Init()
{
    m_context->m_assets->AddFont(MAIN_FONT, "assets/fonts/NotoSerifTC-Medium.otf");
    // Title
    m_playerInfoTitle.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_playerInfoTitle.setString(L"玩家資訊");
    m_playerInfoTitle.setFillColor(sf::Color::Black);
    m_playerInfoTitle.setOrigin(m_playerInfoTitle.getLocalBounds().width / 2,
                                m_playerInfoTitle.getLocalBounds().height / 2);
    m_playerInfoTitle.setPosition(m_context->m_window->getSize().x / 2 - 80.f,
                             m_context->m_window->getSize().y / 2 - 530.f);
    m_playerInfoTitle.setCharacterSize(84);

    // Content
    m_nameText.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_nameText.setString((*m_context->m_userInfoVec)[*m_context->m_currUserindex].User);
    m_nameText.setFillColor(sf::Color::Black);
    m_nameText.setOrigin(m_nameText.getLocalBounds().width / 2,
                         m_nameText.getLocalBounds().height / 2);
    m_nameText.setPosition(m_context->m_window->getSize().x / 2 + 100.f,
                         m_context->m_window->getSize().y / 2 - 330.f);
    m_nameText.setCharacterSize(64);
    m_nameTextIcon.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_nameTextIcon.setString(L"姓名");
    m_nameTextIcon.setFillColor(sf::Color::Black);
    m_nameTextIcon.setOrigin(m_nameTextIcon.getLocalBounds().width / 2,
                         m_nameTextIcon.getLocalBounds().height / 2);
    m_nameTextIcon.setPosition(m_context->m_window->getSize().x / 2 - 150.f,
                           m_context->m_window->getSize().y / 2 - 330.f);
    m_nameTextIcon.setCharacterSize(64);

    m_totalQuesAnswered.setCharacterSize(64);
    m_totalQuesAnswered.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_totalQuesAnswered.setString(std::to_string((*m_context->m_userInfoVec)[*m_context->m_currUserindex].TotalQuesAnswered));
    m_totalQuesAnswered.setFillColor(sf::Color::Black);
    m_totalQuesAnswered.setOrigin(m_totalQuesAnswered.getLocalBounds().width / 2,
                                  m_totalQuesAnswered.getLocalBounds().height / 2);
    m_totalQuesAnswered.setPosition(m_context->m_window->getSize().x / 2 + 100.f,
                           m_context->m_window->getSize().y / 2 - 205.f);
    m_totalQuesAnsweredIcon.setCharacterSize(64);
    m_totalQuesAnsweredIcon.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_totalQuesAnsweredIcon.setString(L"總答題數");
    m_totalQuesAnsweredIcon.setFillColor(sf::Color::Black);
    m_totalQuesAnsweredIcon.setOrigin(m_totalQuesAnsweredIcon.getLocalBounds().width / 2,
                                  m_totalQuesAnsweredIcon.getLocalBounds().height / 2);
    m_totalQuesAnsweredIcon.setPosition(m_context->m_window->getSize().x / 2 - 150.f,
                                    m_context->m_window->getSize().y / 2 - 205.f);
    m_totalQuesAnsweredIcon.setCharacterSize(64);

    m_timeUsed.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_timeUsed.setString(std::to_string((*m_context->m_userInfoVec)[*m_context->m_currUserindex].TimeUsed));
    m_timeUsed.setFillColor(sf::Color::Black);
    m_timeUsed.setOrigin(m_timeUsed.getLocalBounds().width / 2,
                         m_timeUsed.getLocalBounds().height / 2);
    m_timeUsed.setPosition(m_context->m_window->getSize().x / 2 + 100.f,
                           m_context->m_window->getSize().y / 2 - 80.f);
    m_timeUsed.setCharacterSize(64);
    m_timeUsedIcon.setCharacterSize(64);
    m_timeUsedIcon.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_timeUsedIcon.setString(L"花費時間");
    m_timeUsedIcon.setFillColor(sf::Color::Black);
    m_timeUsedIcon.setOrigin(m_timeUsedIcon.getLocalBounds().width / 2,
                         m_timeUsedIcon.getLocalBounds().height / 2);
    m_timeUsedIcon.setPosition(m_context->m_window->getSize().x / 2 - 150.f,
                           m_context->m_window->getSize().y / 2 - 80.f);
    m_timeUsedIcon.setCharacterSize(64);

    m_completeStatus.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    if ((*m_context->m_userInfoVec)[*m_context->m_currUserindex].CompleteStatus)
        m_completeStatus.setString(L"是");
    else
        m_completeStatus.setString(L"否");
    m_completeStatus.setFillColor(sf::Color::Black);
    m_completeStatus.setOrigin(m_completeStatus.getLocalBounds().width / 2,
                               m_completeStatus.getLocalBounds().height / 2);
    m_completeStatus.setPosition(m_context->m_window->getSize().x / 2 + 100.f,
                           m_context->m_window->getSize().y / 2 + 45.f);
    m_completeStatus.setCharacterSize(64);
    m_completeStatusIcon.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_completeStatusIcon.setString(L"是否破關");
    m_completeStatusIcon.setFillColor(sf::Color::Black);
    m_completeStatusIcon.setOrigin(m_completeStatusIcon.getLocalBounds().width / 2,
                               m_completeStatusIcon.getLocalBounds().height / 2);
    m_completeStatusIcon.setPosition(m_context->m_window->getSize().x / 2 - 200.f,
                                 m_context->m_window->getSize().y / 2 + 45.f);
    m_completeStatusIcon.setCharacterSize(64);

    m_currLevel.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_currLevel.setString(std::to_string((*m_context->m_userInfoVec)[*m_context->m_currUserindex].CurrentLv));
    m_currLevel.setFillColor(sf::Color::Black);
    m_currLevel.setOrigin(m_currLevel.getLocalBounds().width / 2,
                              m_currLevel.getLocalBounds().height / 2);
    m_currLevel.setPosition(m_context->m_window->getSize().x / 2 + 100.f,
                                m_context->m_window->getSize().y / 2 + 170.f);
    m_currLevel.setCharacterSize(64);
    m_currLevelIcon.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_currLevelIcon.setString(L"目前關卡");
    m_currLevelIcon.setFillColor(sf::Color::Black);
    m_currLevelIcon.setOrigin(m_currLevelIcon.getLocalBounds().width / 2,
                          m_currLevelIcon.getLocalBounds().height / 2);
    m_currLevelIcon.setPosition(m_context->m_window->getSize().x / 2 - 200.f,
                           m_context->m_window->getSize().y / 2 + 170.f);
    m_currLevelIcon.setCharacterSize(64);

    /*m_bannedTime.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_bannedTime.setString(std::to_string((*m_context->m_userInfoVec)[*m_context->m_currUserindex].BannedTime));
    m_bannedTime.setFillColor(sf::Color::Black);
    m_bannedTime.setOrigin(m_bannedTime.getLocalBounds().width / 2,
                           m_bannedTime.getLocalBounds().height / 2);
    m_bannedTime.setPosition(m_context->m_window->getSize().x / 2 + 100.f,
                           m_context->m_window->getSize().y / 2 + 20.f);
    m_bannedTime.setCharacterSize(30);*/


    // Buttons
    m_returnMenuButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_returnMenuButton.setString(L"上一頁");
    m_returnMenuButton.setFillColor(sf::Color::Black);
    m_returnMenuButton.setOrigin(m_returnMenuButton.getLocalBounds().width / 2,
                                 m_returnMenuButton.getLocalBounds().height / 2);
    m_returnMenuButton.setPosition(m_context->m_window->getSize().x / 2 - 30.f,
                                   m_context->m_window->getSize().y / 2 + 500.f);
    m_returnMenuButton.setCharacterSize(64);

    // load texture and sprite
    if (!m_bgImage.loadFromFile("assets/background/original_light_new.jpg"))// background image
        std::cout << "no data exists!";
    m_bgImageDraw.setTexture(m_bgImage);

}

void PlayerInfo::ProcessInput()
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

void PlayerInfo::Update(sf::Time deltaTime)
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
        m_context->m_states->Add(std::make_unique<InternalWelcome>(m_context));
    }
}

void PlayerInfo::Draw()
{
    m_context->m_window->clear();
    m_context->m_window->draw(m_bgImageDraw);
    m_context->m_window->draw(m_playerInfoTitle);
    m_context->m_window->draw(m_nameText);
    m_context->m_window->draw(m_totalQuesAnswered);
    m_context->m_window->draw(m_timeUsed);
    m_context->m_window->draw(m_completeStatus);
    m_context->m_window->draw(m_currLevel);
    //m_context->m_window->draw(m_bannedTime);
    m_context->m_window->draw(m_nameTextIcon);
    m_context->m_window->draw(m_totalQuesAnsweredIcon);
    m_context->m_window->draw(m_timeUsedIcon);
    m_context->m_window->draw(m_completeStatusIcon);
    m_context->m_window->draw(m_currLevelIcon);
    m_context->m_window->draw(m_returnMenuButton);
    m_context->m_window->display();
}
