#include "../include/MakeWish.h"
#include "../include/MainMenu.h"
#include "../include/Game.h"

#include <SFML/Window/Event.hpp>
#include <iostream>

MakeWish::MakeWish(std::shared_ptr<Context> &context)
        : m_context(context),
          m_isSubmitButtonSelected(false), m_isSubmitButtonPressed(false),
          m_isWishBoxSelected(false), m_isWishBoxPressed(false),
          m_wish("")

{
}

MakeWish::~MakeWish()
{
}

bool MakeWish::IsTextSelected(sf::Text object)
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


bool MakeWish::IsTextClicked(sf::Text object, sf::Mouse::Button button)
{
    if (sf::Mouse::isButtonPressed(button) && IsTextSelected(object))
        return true;
    return false;
}

bool MakeWish::IsBoxSelected(sf::RectangleShape object)
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


bool MakeWish::IsBoxClicked(sf::RectangleShape object, sf::Mouse::Button button)
{
    if (sf::Mouse::isButtonPressed(button) && IsBoxSelected(object))
        return true;
    return false;
}


void MakeWish::InputLogic(int charTyped, std::string &s)
{
    if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY)
        s.push_back(static_cast<char>(charTyped));
    else if (charTyped == DELETE_KEY && s.length() > 0)
        s.pop_back();
}


void MakeWish::Init()
{
    // Title
    m_makeWishTitle.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_makeWishTitle.setString(L"????????????????????????");
    m_makeWishTitle.setFillColor(sf::Color::Black);
    m_makeWishTitle.setOrigin(m_makeWishTitle.getLocalBounds().width / 2,
                              m_makeWishTitle.getLocalBounds().height / 2);
    m_makeWishTitle.setPosition(m_context->m_window->getSize().x / 2 - 150.f,
                              m_context->m_window->getSize().y / 2 - 530.f);
    m_makeWishTitle.setCharacterSize(84);
    // Buttons
    m_submitButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_submitButton.setString(L"??????");
    m_submitButton.setFillColor(sf::Color::Black);
    m_submitButton.setOrigin(m_submitButton.getLocalBounds().width / 2,
                             m_submitButton.getLocalBounds().height / 2);
    m_submitButton.setPosition(m_context->m_window->getSize().x / 2 - 30.f,
                                   m_context->m_window->getSize().y / 2 + 450.f);
    m_submitButton.setCharacterSize(64);
    // Textboxes
    m_wishBox.setSize(sf::Vector2f(1000, 800));
    m_wishBox.setFillColor(sf::Color::White);
    m_wishBox.setOutlineThickness(4);
    m_wishBox.setOrigin(m_wishBox.getLocalBounds().width / 2,
                        m_wishBox.getLocalBounds().height / 2);
    m_wishBox.setPosition(m_context->m_window->getSize().x / 2,
                              m_context->m_window->getSize().y / 2 + 25.f);


    // Box Text
    m_wishText.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_wishText.setFillColor(sf::Color::Black);
    m_wishText.setString(m_wish);
    m_wishText.setOrigin(m_wishBox.getLocalBounds().width / 2,
                         m_wishBox.getLocalBounds().height / 2);
    m_wishText.setPosition(m_context->m_window->getSize().x / 2,
                           m_context->m_window->getSize().y / 2 + 25.f);
    m_wishText.setCharacterSize(40);

    //Sprite
    m_context->m_assets->AddTexture(PROF, "assets/textures/8-1.png");
    m_prof.setTexture(m_context->m_assets->GetTexture(PROF));
    m_prof.setPosition(m_context->m_window->getSize().x / 2 + 450.f, m_context->m_window->getSize().y / 2 - 250.f);

    // load image
    if (!m_bgImage.loadFromFile("assets/background/original_light_new.jpg"))// background image
        std::cout << "no data exists!";
    m_bgIamgeDraw.setTexture(m_bgImage);
}

void MakeWish::ProcessInput()
{
    sf::Event event;
    while (m_context->m_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_context->m_window->close();
        }

        if (IsTextSelected(m_submitButton))
        {
            m_isSubmitButtonSelected = true;
            m_isWishBoxSelected = false;
        }
        else if (IsBoxSelected(m_wishBox))
        {
            m_isSubmitButtonSelected = false;
            m_isWishBoxSelected = true;
        }
        else
        {
            m_isSubmitButtonSelected = false;
            m_isWishBoxSelected = false;
        }

        if (IsTextClicked(m_submitButton, sf::Mouse::Left))
        {
            m_isSubmitButtonPressed = true;
            m_isWishBoxPressed = false;
        }
        else if (IsBoxClicked(m_wishBox, sf::Mouse::Left))
        {
            m_isSubmitButtonPressed = false;
            m_isWishBoxPressed = true;
        }
        else
        {
            m_isSubmitButtonPressed = false;
        }

        if (event.type == sf::Event::TextEntered && (m_isWishBoxPressed))
        {
            int charTyped = event.text.unicode;
            if (charTyped < 256)
            {
                InputLogic(charTyped, m_wish);
                m_wishText.setString(m_wish + "|");
            }
        }
    }
}

void MakeWish::Update(sf::Time deltaTime)
{
    if (m_isSubmitButtonSelected)
    {
        m_submitButton.setFillColor(sf::Color(121,2,2));
        m_wishBox.setOutlineColor(sf::Color::Black);
    }
    else if (m_isWishBoxSelected)
    {
        m_submitButton.setFillColor(sf::Color::Black);
        m_wishBox.setOutlineColor(sf::Color(121,2,2));
    }
    else
    {
        m_submitButton.setFillColor(sf::Color::Black);
        m_wishBox.setOutlineColor(sf::Color::Black);
    }

    if (m_isSubmitButtonPressed)
    {
        (*m_context->m_userInfoVec)[*m_context->m_currUserindex].Wish = m_wish;
        m_context->m_states->PopCurrent();
        m_context->m_states->Add(std::make_unique<MainMenu>(m_context));
    }
    else if (m_isWishBoxPressed)
    {
        m_wishBox.setOutlineColor(sf::Color::Black);
        m_wishText.setString(m_wish);
        //std::cout << m_wish << '\n';
    }

}

void MakeWish::Draw()
{
    m_context->m_window->clear(sf::Color::Blue);
    m_context->m_window->draw(m_bgIamgeDraw);
    m_context->m_window->draw(m_makeWishTitle);
    m_context->m_window->draw(m_submitButton);
    m_context->m_window->draw(m_wishBox);
    m_context->m_window->draw(m_wishText);
    m_context->m_window->draw(m_prof);
    m_context->m_window->display();
}


