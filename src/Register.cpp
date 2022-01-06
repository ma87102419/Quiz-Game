#include "../include/Register.h"
#include "../include/MainMenu.h"
#include "../include/Welcome.h"
#include "../include/InternalWelcome.h"


#include <SFML/Window/Event.hpp>


Register::Register(std::shared_ptr<Context> &context)
        : m_context(context),
          m_isReturnMenuButtonSelected(false), m_isReturnMenuButtonPressed(false),
          m_isRegisterButtonSelected(false), m_isRegisterButtonPressed(false),
          m_isUserBoxSelected(false), m_isUserBoxPressed(false),
          m_isPwdBoxSelected(false), m_isPwdBoxPressed(false),
          m_userInfoFile("assets/Info/user_info_utf8.txt"),
          m_name(""), m_password(""),
          m_validUser(true)
{
}

Register::~Register()
{
}

bool Register::IsTextSelected(sf::Text object)
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


bool Register::IsTextClicked(sf::Text object, sf::Mouse::Button button)
{
    if (sf::Mouse::isButtonPressed(button) && IsTextSelected(object))
        return true;
    return false;
}

bool Register::IsBoxSelected(sf::RectangleShape object)
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


bool Register::IsBoxClicked(sf::RectangleShape object, sf::Mouse::Button button)
{
    if (sf::Mouse::isButtonPressed(button) && IsBoxSelected(object))
        return true;
    return false;
}


void Register::InputLogic(int charTyped, std::string &s)
{
    if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY && charTyped != SPACE_KEY)
        s.push_back(static_cast<char>(charTyped));
    else if (charTyped == DELETE_KEY && s.length() > 0)
        s.pop_back();
}

std::string Register::MaskPwd(std::string s)
{
    std::string masked_s = "";
    for (int i = 0; i < s.length(); i++)
        masked_s.push_back('*');
    return masked_s;
}

void Register::Init()
{
    // Title
    m_registerTitle.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_registerTitle.setString(L"註冊來開始遊戲");
    m_registerTitle.setOrigin(m_registerTitle.getLocalBounds().width / 2,
                            m_registerTitle.getLocalBounds().height / 2);
    m_registerTitle.setPosition(m_context->m_window->getSize().x / 2 - 300.f,
                              m_context->m_window->getSize().y / 2 - 330.f);
    m_registerTitle.setCharacterSize(54);
    // Buttons
    m_registerButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_registerButton.setString(L"註冊");
    m_registerButton.setOrigin(m_registerButton.getLocalBounds().width / 2,
                            m_registerButton.getLocalBounds().height / 2);
    m_registerButton.setPosition(m_context->m_window->getSize().x / 2,
                              m_context->m_window->getSize().y / 2);
    m_registerButton.setCharacterSize(40);

    m_backButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_backButton.setString(L"上一頁");
    m_backButton.setOrigin(m_backButton.getLocalBounds().width / 2,
                           m_backButton.getLocalBounds().height / 2);
    m_backButton.setPosition(m_context->m_window->getSize().x / 2,
                             m_context->m_window->getSize().y / 2 + 150.f);
    m_backButton.setCharacterSize(40);

    m_returnMenuButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_returnMenuButton.setString(L"回到主選單");
    m_returnMenuButton.setOrigin(m_returnMenuButton.getLocalBounds().width / 2,
                                 m_returnMenuButton.getLocalBounds().height / 2);
    m_returnMenuButton.setPosition(m_context->m_window->getSize().x / 2,
                                   m_context->m_window->getSize().y / 2 + 225.f);
    m_returnMenuButton.setCharacterSize(40);

    // user name and pwd
    m_userName.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_userName.setString(L"使用者名稱 : ");
    m_userName.setOrigin(m_userName.getLocalBounds().width / 2,
                         m_userName.getLocalBounds().height / 2);
    m_userName.setPosition(m_context->m_window->getSize().x / 2 - 150.f,
                           m_context->m_window->getSize().y / 2 - 120.f);
    m_userName.setCharacterSize(40);

    m_pwd.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_pwd.setString(L"密碼 : ");
    m_pwd.setOrigin(m_pwd.getLocalBounds().width / 2,
                    m_pwd.getLocalBounds().height / 2);
    m_pwd.setPosition(m_context->m_window->getSize().x / 2 - 200.f,
                      m_context->m_window->getSize().y / 2 - 60.f);
    m_pwd.setCharacterSize(40);
    // Textboxes
    m_userNameBox.setSize(sf::Vector2f(300, 30));
    m_userNameBox.setFillColor(sf::Color::White);
    m_userNameBox.setOutlineThickness(2);
    m_userNameBox.setOrigin(m_userNameBox.getLocalBounds().width / 2,
                            m_userNameBox.getLocalBounds().height / 2);
    m_userNameBox.setPosition(m_context->m_window->getSize().x / 2 + 90.f,
                              m_context->m_window->getSize().y / 2 - 100.f);

    m_pwdBox.setSize(sf::Vector2f(300, 30));
    m_pwdBox.setFillColor(sf::Color::White);
    m_pwdBox.setOutlineThickness(2);
    m_pwdBox.setOrigin(m_pwdBox.getLocalBounds().width / 2,
                       m_pwdBox.getLocalBounds().height / 2);
    m_pwdBox.setPosition(m_context->m_window->getSize().x / 2 + 90.f,
                         m_context->m_window->getSize().y / 2 - 50.f);

    // Box Text
    m_nameText.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_nameText.setFillColor(sf::Color::Black);
    m_nameText.setString(m_name);
    m_nameText.setOrigin(m_userNameBox.getLocalBounds().width / 2,
                         m_userNameBox.getLocalBounds().height / 2);
    m_nameText.setPosition(m_context->m_window->getSize().x / 2 + 90.f,
                           m_context->m_window->getSize().y / 2 -100.f);
    m_nameText.setCharacterSize(25);

    m_pwdText.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_pwdText.setFillColor(sf::Color::Black);
    m_pwdText.setString(Register::MaskPwd(m_password));
    m_pwdText.setOrigin(m_pwdBox.getLocalBounds().width / 2,
                        m_pwdBox.getLocalBounds().height / 2);
    m_pwdText.setPosition(m_context->m_window->getSize().x / 2 + 90.f,
                          m_context->m_window->getSize().y / 2 - 50.f);
    m_pwdText.setCharacterSize(25);

    if(m_userInfoFile)
    {
        int i = 0;
        while(m_userInfoFile >> tmp_username >>  tmp_password >> tmp_complete_status >> tmp_total_ques_answered >> tmp_time_used >>
                             tmp_life >> tmp_current_lv >> tmp_account_status >> tmp_wish >> tmp_wish_status >> tmp_banned_status >> tmp_banned_time)
        {
            tmpUserArray[i] = tmp_username;
            tmpPwdArray[i] = tmp_password;
            tmpCompleteStatusArray[i] = tmp_complete_status;
            tmpTotalQuesAnsweredArray[i] = tmp_total_ques_answered;
            tmpTimeUsedArray[i] = tmp_time_used;
            tmpLifeArray[i] = tmp_life;
            tmpCurrentLvArray[i] = tmp_current_lv;
            tmpAccountStatusArray[i] = tmp_account_status;
            tmpWishArray[i] = tmp_wish;
            tmpWishStatusArray[i] = tmp_wish_status;
            tmpBannedStatusArray[i] = tmp_banned_status;
            tmpBannedTimeArray[i] = tmp_banned_time;
            i ++;
        }
        m_allUser = i;
    }


}

void Register::ProcessInput()
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
            m_isRegisterButtonSelected = false;
            m_isBackButtonSelected = false;
            m_isUserBoxSelected = false;
            m_isPwdBoxSelected = false;
        }
        else if (IsTextSelected(m_registerButton))
        {
            m_isReturnMenuButtonSelected = false;
            m_isRegisterButtonSelected = true;
            m_isBackButtonSelected = false;
            m_isUserBoxSelected = false;
            m_isPwdBoxSelected = false;
        }
        else if (IsTextSelected(m_backButton))
        {
            m_isReturnMenuButtonSelected = false;
            m_isRegisterButtonSelected = false;
            m_isBackButtonSelected = true;
            m_isUserBoxSelected = false;
            m_isPwdBoxSelected = false;
        }
        else if (IsBoxSelected(m_userNameBox))
        {
            m_isReturnMenuButtonSelected = false;
            m_isRegisterButtonSelected = false;
            m_isBackButtonSelected = false;
            m_isUserBoxSelected = true;
            m_isPwdBoxSelected = false;
        }

        else if (IsBoxSelected(m_pwdBox))
        {
            m_isReturnMenuButtonSelected = false;
            m_isRegisterButtonSelected = false;
            m_isBackButtonSelected = false;
            m_isUserBoxSelected = false;
            m_isPwdBoxSelected = true;
        }
        else
        {
            m_isReturnMenuButtonSelected = false;
            m_isRegisterButtonSelected = false;
            m_isBackButtonSelected = false;
            m_isUserBoxSelected = false;
            m_isPwdBoxSelected = false;
        }

        if (IsTextClicked(m_returnMenuButton, sf::Mouse::Left))
        {
            m_isReturnMenuButtonPressed = true;
            m_isRegisterButtonPressed = false;
            m_isBackButtonPressed = false;
            m_isUserBoxPressed = false;
            m_isPwdBoxPressed = false;
        }
        else if (IsTextClicked(m_registerButton, sf::Mouse::Left))
        {
            m_isReturnMenuButtonPressed = false;
            m_isRegisterButtonPressed = true;
            m_isBackButtonPressed = false;
            m_isUserBoxPressed = false;
            m_isPwdBoxPressed = false;
        }
        else if (IsTextClicked(m_backButton, sf::Mouse::Left))
        {
            m_isReturnMenuButtonPressed = false;
            m_isRegisterButtonPressed = false;
            m_isBackButtonPressed = true;
            m_isUserBoxPressed = false;
            m_isPwdBoxPressed = false;
        }
        else if (IsBoxClicked(m_userNameBox, sf::Mouse::Left))
        {
            m_isReturnMenuButtonPressed = false;
            m_isRegisterButtonPressed = false;
            m_isBackButtonPressed = false;
            m_isUserBoxPressed = true;
            m_isPwdBoxPressed = false;
        }
        else if (IsBoxClicked(m_pwdBox, sf::Mouse::Left))
        {
            m_isReturnMenuButtonPressed = false;
            m_isRegisterButtonPressed = false;
            m_isBackButtonPressed = false;
            m_isUserBoxPressed = false;
            m_isPwdBoxPressed = true;
        }
        else
        {
            m_isReturnMenuButtonPressed = false;
            m_isRegisterButtonPressed = false;
            m_isBackButtonPressed = false;
        }

        if (event.type == sf::Event::TextEntered && (m_isUserBoxPressed || m_isPwdBoxPressed))
        {
            int charTyped = event.text.unicode;
            if (charTyped < 256) {
                if (m_isUserBoxPressed)
                {
                    InputLogic(charTyped, m_name);
                    m_nameText.setString(m_name + "|");
                }
                else
                {
                    InputLogic(charTyped, m_password);
                    m_pwdText.setString(Register::MaskPwd(m_password) + "|");
                }
            }
        }
    }
    for (int i = 0; i < m_allUser; i++)
    {
        if (m_name == tmpUserArray[i])
        {
            m_validUser = false;
            break;
        }
        if (m_validUser)
        {
            m_allUser += 1;
            tmpUserArray[m_allUser] = m_name;
            tmpPwdArray[m_allUser] = m_password;
            tmpCompleteStatusArray[m_allUser] = 0;
            tmpTotalQuesAnsweredArray[m_allUser] = 0;
            tmpTimeUsedArray[m_allUser] = 0;
            tmpLifeArray[m_allUser] = 5;
            tmpCurrentLvArray[m_allUser] = 1;
            tmpAccountStatusArray[m_allUser] = 1;
            tmpWishArray[m_allUser] = "";
            tmpWishStatusArray[m_allUser] = 0;
            tmpBannedStatusArray[m_allUser] = 0;
            tmpBannedTimeArray[m_allUser] = 0;
        }
    }

}

void Register::Update(sf::Time deltaTime)
{
    if (m_isReturnMenuButtonSelected)
    {
        m_returnMenuButton.setFillColor(sf::Color::Black);
        m_registerButton.setFillColor(sf::Color::White);
        m_backButton.setFillColor(sf::Color::White);
        m_userNameBox.setOutlineColor(sf::Color::White);
        m_pwdBox.setOutlineColor(sf::Color::White);
    }
    else if (m_isRegisterButtonSelected)
    {
        m_returnMenuButton.setFillColor(sf::Color::White);
        m_registerButton.setFillColor(sf::Color::Black);
        m_backButton.setFillColor(sf::Color::White);
        m_userNameBox.setOutlineColor(sf::Color::White);
        m_pwdBox.setOutlineColor(sf::Color::White);
    }
    else if (m_isBackButtonSelected)
    {
        m_returnMenuButton.setFillColor(sf::Color::White);
        m_registerButton.setFillColor(sf::Color::White);
        m_backButton.setFillColor(sf::Color::Black);
        m_userNameBox.setOutlineColor(sf::Color::White);
        m_pwdBox.setOutlineColor(sf::Color::White);
    }
    else if (m_isUserBoxSelected)
    {
        m_returnMenuButton.setFillColor(sf::Color::White);
        m_registerButton.setFillColor(sf::Color::White);
        m_backButton.setFillColor(sf::Color::White);
        m_userNameBox.setOutlineColor(sf::Color::Black);
        m_pwdBox.setOutlineColor(sf::Color::White);
    }
    else if (m_isPwdBoxSelected)
    {
        m_returnMenuButton.setFillColor(sf::Color::White);
        m_registerButton.setFillColor(sf::Color::White);
        m_backButton.setFillColor(sf::Color::White);
        m_userNameBox.setOutlineColor(sf::Color::White);
        m_pwdBox.setOutlineColor(sf::Color::Black);
    }
    else
    {
        m_returnMenuButton.setFillColor(sf::Color::White);
        m_registerButton.setFillColor(sf::Color::White);
        m_backButton.setFillColor(sf::Color::White);
        m_userNameBox.setOutlineColor(sf::Color::White);
        m_pwdBox.setOutlineColor(sf::Color::White);
    }

    if (m_isReturnMenuButtonPressed)
    {
        m_context->m_states->PopCurrent();
        m_context->m_states->Add(std::make_unique<MainMenu>(m_context));
    }
    else if (m_isBackButtonPressed)
    {
        m_context->m_states->PopCurrent();
        m_context->m_states->Add(std::make_unique<Welcome>(m_context));
    }
    else if (m_isRegisterButtonPressed) // TODO &&...check valid user
    {
        m_context->m_states->PopCurrent();
        *m_context->m_currUser = m_name;
        m_context->m_states->Add(std::make_unique<InternalWelcome>(m_context));
    }
    else if (m_isUserBoxPressed)
    {
        m_userNameBox.setOutlineColor(sf::Color::Black);
        m_pwdBox.setOutlineColor(sf::Color::White);
        m_nameText.setString(m_name + '|');
        m_pwdText.setString(Register::MaskPwd(m_password));
    }
    else if (m_isPwdBoxPressed)
    {
        m_pwdBox.setOutlineColor(sf::Color::Black);
        m_userNameBox.setOutlineColor(sf::Color::White);
        m_nameText.setString(m_name);
        m_pwdText.setString(Register::MaskPwd(m_password) + '|');
    }

}

void Register::Draw()
{
    m_context->m_window->clear(sf::Color::Blue);
    m_context->m_window->draw(m_registerTitle);
    m_context->m_window->draw(m_returnMenuButton);
    m_context->m_window->draw(m_registerButton);
    m_context->m_window->draw(m_backButton);
    m_context->m_window->draw(m_userName);
    m_context->m_window->draw(m_pwd);
    m_context->m_window->draw(m_userNameBox);
    m_context->m_window->draw(m_pwdBox);
    m_context->m_window->draw(m_nameText);
    m_context->m_window->draw(m_pwdText);
    m_context->m_window->display();
}
