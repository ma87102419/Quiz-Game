#include "../include/Introduction.h"
#include "../include/MainMenu.h"
#include<iostream>
#include <SFML/Window/Event.hpp>

Introduction::Introduction(std::shared_ptr<Context> &context)
        : m_context(context),
          m_isReturnMenuButtonSelected(false), m_isReturnMenuButtonPressed(false)
{
}

Introduction::~Introduction()
{
}

bool Introduction::IsTextSelected(sf::Text object)
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


bool Introduction::IsTextClicked(sf::Text object, sf::Mouse::Button button)
{
    if (sf::Mouse::isButtonPressed(button) && IsTextSelected(object))
        return true;
    return false;
}

void Introduction::Init()
{
    // Title
    m_introTitle.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_introTitle.setString(L"遊戲介紹");
    m_introTitle.setFillColor(sf::Color::Black);
    m_introTitle.setOrigin(m_introTitle.getLocalBounds().width / 2,
                           m_introTitle.getLocalBounds().height / 2);
    m_introTitle.setPosition(m_context->m_window->getSize().x / 2 - 45.f,
                             m_context->m_window->getSize().y / 2 - 300.f);
    m_introTitle.setCharacterSize(54);

    // Buttons
    m_returnMenuButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_returnMenuButton.setString(L"回到主選單");
    m_returnMenuButton.setFillColor(sf::Color::Black);
    m_returnMenuButton.setOrigin(m_returnMenuButton.getLocalBounds().width / 2,
                                 m_returnMenuButton.getLocalBounds().height / 2);
    m_returnMenuButton.setPosition(m_context->m_window->getSize().x / 2,
                                   m_context->m_window->getSize().y / 2 + 100.f);
    m_returnMenuButton.setCharacterSize(40);

    // load texture and sprite
    if (!m_bgImage.loadFromFile("assets/background/original_light_new.jpg"))// background image
        std::cout << "no data exists!";
    m_bgImageDraw.setTexture(m_bgImage);

    // Content
    sf::String contentText = L"某天，你突然發現你深陷在夢中，醒不過來。現實中，你只是一個混到畢業的資管系學生，"
                             "目前是個什麼程式都不會打的無業遊民。你以為在夢裡就能有錢有房有車有女友，結果卻發現在夢中也不能為所欲為，"
                             "每天只能去超商買即期食品...今天一如往常騎著腳踏車，到超商買微波食品的路上，不只沒有幸運的事情發生，"
                             "你還為了閃躲走在自行車道的移動式路障，整個人摔進了花叢中，雖然沒有受傷，"
                             "但腳踏車的車籃直接撞成一個茶壺的形狀當你心疼的摸著車籃的時候，你發現，原來是地上那個破茶壺，"
                             "把你的車籃弄成這樣，一氣之下，用力地踹了一腳，你「噢嗚！」了一聲，卻也聽到破茶壺「噢嗚！」了一聲，"
                             "轉頭想拔腿就跑的你，發現忘了騎腳踏車心理雖然很害怕，但是但是更害怕自己什麼都沒有了，"
                             "所以不能連腳踏車都沒有。正當你一回頭，就被吸進了茶壺的世界，這裡黑漆漆的，只有一台遊戲機，"
                             "上面寫著：想想你的大學生活到底經歷了什麼吧！如果能夠破完全部的關卡，我就考慮實現你一個願望～～";
    //contentText += "\n";
    //contentText += L"目前是個什麼程式都不會打的無業遊民。";
    m_introContent.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_introContent.setString(contentText);
    m_introContent.setFillColor(sf::Color::Black);
    m_introContent.setOrigin(m_introContent.getLocalBounds().width / 2,
                             m_introContent.getLocalBounds().height / 2);
    m_introContent.setPosition(m_context->m_window->getSize().x / 2,
                                   m_context->m_window->getSize().y / 2 -250.f);

}

void Introduction::ProcessInput()
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

void Introduction::Update(sf::Time deltaTime)
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

void Introduction::Draw()
{
    m_context->m_window->clear();
    m_context->m_window->draw(m_bgImageDraw);
    m_context->m_window->draw(m_introTitle);
    m_context->m_window->draw(m_introContent);
    m_context->m_window->draw(m_returnMenuButton);
    m_context->m_window->display();
}
