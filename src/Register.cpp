#include "../include/Register.h"
#include "../include/MainMenu.h"
#include "../include/Welcome.h"
#include "../include/InternalWelcome.h"
#include "../include/Game.h"


#include <SFML/Window/Event.hpp>


Register::Register(std::shared_ptr<Context> &context)
        : m_context(context),
          m_isReturnMenuButtonSelected(false), m_isReturnMenuButtonPressed(false),
          m_isRegisterButtonSelected(false), m_isRegisterButtonPressed(false),
          m_isUserBoxSelected(false), m_isUserBoxPressed(false),
          m_isPwdBoxSelected(false), m_isPwdBoxPressed(false),
          m_name(""), m_password(""), m_showErrorMsg(false),
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
    m_registerTitle.setString(L"註冊來開始遊戲吧！");
    //m_registerTitle.setFillColor(sf::Color::Black);
    m_registerTitle.setOrigin(m_registerTitle.getLocalBounds().width / 2,
                            m_registerTitle.getLocalBounds().height / 2);
    m_registerTitle.setPosition(m_context->m_window->getSize().x / 2 - 250.f,
                              m_context->m_window->getSize().y / 2 - 530.f);
    m_registerTitle.setCharacterSize(84);
    // Buttons
    m_registerButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_registerButton.setString(L"註冊");
   // m_registerButton.setFillColor(sf::Color::Black);
    m_registerButton.setOrigin(m_registerButton.getLocalBounds().width / 2,
                            m_registerButton.getLocalBounds().height / 2);
    m_registerButton.setPosition(m_context->m_window->getSize().x / 2,
                              m_context->m_window->getSize().y / 2 + 120.f);
    m_registerButton.setCharacterSize(65);

    // error message
    m_errorMsg.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_errorMsg.setFillColor(sf::Color(255, 0, 0));
    m_errorMsg.setString(L"此帳號已被註冊過/帳密空白！");
    m_errorMsg.setOrigin(m_errorMsg.getLocalBounds().width / 2,
                         m_errorMsg.getLocalBounds().height / 2);
    m_errorMsg.setPosition(m_context->m_window->getSize().x / 2,
        m_context->m_window->getSize().y / 2 + 80.f);
    m_errorMsg.setCharacterSize(40);

    // back button
    m_backButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_backButton.setString(L"上一頁");
    //m_backButton.setFillColor(sf::Color::Black);
    m_backButton.setOrigin(m_backButton.getLocalBounds().width / 2,
                           m_backButton.getLocalBounds().height / 2);
    m_backButton.setPosition(m_context->m_window->getSize().x / 2,
                             m_context->m_window->getSize().y / 2 + 370.f);
    m_backButton.setCharacterSize(64);

    m_returnMenuButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_returnMenuButton.setString(L"回到主選單");
   // m_returnMenuButton.setFillColor(sf::Color::Black);
    m_returnMenuButton.setOrigin(m_returnMenuButton.getLocalBounds().width / 2,
                                 m_returnMenuButton.getLocalBounds().height / 2);
    m_returnMenuButton.setPosition(m_context->m_window->getSize().x / 2 - 20.f,
                                   m_context->m_window->getSize().y / 2 + 520.f);
    m_returnMenuButton.setCharacterSize(64);

    // user name and pwd
    m_userName.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_userName.setString(L"使用者名稱 : ");
    //m_userName.setFillColor(sf::Color::Black);
    m_userName.setOrigin(m_userName.getLocalBounds().width / 2,
                         m_userName.getLocalBounds().height / 2);
    m_userName.setPosition(m_context->m_window->getSize().x / 2 - 285.f,
                           m_context->m_window->getSize().y / 2 - 120.f);
    m_userName.setCharacterSize(64);

    m_UserPwd.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_UserPwd.setString(L"密碼 : ");
   // m_pwd.setFillColor(sf::Color::Black);
    m_UserPwd.setOrigin(m_UserPwd.getLocalBounds().width / 2,
                    m_UserPwd.getLocalBounds().height / 2);
    m_UserPwd.setPosition(m_context->m_window->getSize().x / 2 - 140.f,
                      m_context->m_window->getSize().y / 2 - 20.f);
    m_UserPwd.setCharacterSize(64);
    // Textboxes
    m_userNameBox.setSize(sf::Vector2f(500, 60));
    m_userNameBox.setFillColor(sf::Color::White);
    m_userNameBox.setOutlineThickness(2);
    m_userNameBox.setOrigin(m_userNameBox.getLocalBounds().width / 2,
                            m_userNameBox.getLocalBounds().height / 2);
    m_userNameBox.setPosition(m_context->m_window->getSize().x / 2 + 250.f,
                              m_context->m_window->getSize().y / 2 - 100.f);

    m_pwdBox.setSize(sf::Vector2f(500, 60));
    m_pwdBox.setFillColor(sf::Color::White);
    m_pwdBox.setOutlineThickness(2);
    m_pwdBox.setOrigin(m_pwdBox.getLocalBounds().width / 2,
                       m_pwdBox.getLocalBounds().height / 2);
    m_pwdBox.setPosition(m_context->m_window->getSize().x / 2 + 250.f,
                         m_context->m_window->getSize().y / 2);

    // Box Text
    m_nameText.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_nameText.setFillColor(sf::Color::Black);
    m_nameText.setString(m_name);
    m_nameText.setOrigin(m_userNameBox.getLocalBounds().width / 2,
                         m_userNameBox.getLocalBounds().height / 2);
    m_nameText.setPosition(m_context->m_window->getSize().x / 2 + 250.f,
                           m_context->m_window->getSize().y / 2 -100.f);
    m_nameText.setCharacterSize(40);

    m_pwdText.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_pwdText.setFillColor(sf::Color::Black);
    m_pwdText.setString(Register::MaskPwd(m_password));
    m_pwdText.setOrigin(m_pwdBox.getLocalBounds().width / 2,
                        m_pwdBox.getLocalBounds().height / 2);
    m_pwdText.setPosition(m_context->m_window->getSize().x / 2 + 250.f,
                          m_context->m_window->getSize().y / 2);
    m_pwdText.setCharacterSize(40);


    // ntu emblem draw
    if (!m_ntuEmblem.loadFromFile("assets/background/Emblem72.png"))// background image
        std::cout << "no data exists!";
    m_ntuEmblemDraw.setTexture(m_ntuEmblem);
    m_ntuEmblemDraw.setPosition(m_context->m_window->getSize().x / 2 - 960.f,
        m_context->m_window->getSize().y / 2 - 530.f);

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
        m_validUser = true;
        for (int i = 0; i < (*m_context->m_userInfoVec).size(); i++)
        {
            if (m_name.length() == 0 || m_password.length() == 0 || m_name == (*m_context->m_userInfoVec)[i].User)
            {
                m_validUser = false;
                break;
            }
        }
        struct UserInfo tmp_info;
        if (m_validUser)
        {
            tmp_info.User = m_name;
            tmp_info.Pwd = m_password;
            tmp_info.CompleteStatus = 0;
            tmp_info.TotalQuesAnswered = 0;
            tmp_info.TimeUsed = 0;
            tmp_info.Life = 5;
            tmp_info.CurrentLv = 1;
            tmp_info.AccountStatus = 1;
            tmp_info.Wish = "";
            tmp_info.WishStatus = 0;
            tmp_info.BannedStatus = 0;
            tmp_info.BannedTime = 0;
            (*m_context->m_userInfoVec).push_back(tmp_info);
            *m_context->m_currUserindex = (*m_context->m_userInfoVec).size() - 1;
            m_context->m_states->PopCurrent(); // move
            m_context->m_states->Add(std::make_unique<InternalWelcome>(m_context)); //move
        }
        else
            m_showErrorMsg = true;
        
    }
    else if (m_isUserBoxPressed)
    {
        m_userNameBox.setOutlineColor(sf::Color::Black); //? 
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
    m_context->m_window->clear(sf::Color(102, 178, 255));
    m_context->m_window->draw(m_registerTitle);
    m_context->m_window->draw(m_returnMenuButton);
    m_context->m_window->draw(m_registerButton);
    m_context->m_window->draw(m_backButton);
    m_context->m_window->draw(m_userName);
    m_context->m_window->draw(m_UserPwd);
    m_context->m_window->draw(m_ntuEmblemDraw);
    m_context->m_window->draw(m_userNameBox);
    m_context->m_window->draw(m_pwdBox);
    m_context->m_window->draw(m_nameText);
    m_context->m_window->draw(m_pwdText);
    if(m_showErrorMsg)
        m_context->m_window->draw(m_errorMsg);
    m_context->m_window->display();
}

