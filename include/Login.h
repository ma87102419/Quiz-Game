#pragma once

#include <memory>
#include <iostream>
#include <sstream>
#include <fstream>

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>

#include "State.h"
#include "Game.h"

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27
#define SPACE_KEY 32

class Login : public Engine::State
{
private:
    std::shared_ptr<Context> m_context;
    sf::Text m_loginTitle;
    sf::Text m_loginButton;
    sf::Text m_returnMenuButton;
    sf::Text m_backButton;
    sf::Text m_userName;
    sf::Text m_pwd;
    sf::Text m_nameText;
    sf::Text m_pwdText;
    sf::Text m_errorMsg; // error when the user typed the wrong username and/or password

    sf::Texture m_ntuEmblem; // background image
    sf::Sprite m_ntuEmblemDraw; // texture to sprite

    sf::RectangleShape m_userNameBox;
    sf::RectangleShape m_pwdBox;

    bool m_isReturnMenuButtonSelected;
    bool m_isReturnMenuButtonPressed;

    bool m_isLoginButtonSelected;
    bool m_isLoginButtonPressed;

    bool m_isBackButtonSelected;
    bool m_isBackButtonPressed;

    bool m_isUserBoxSelected;
    bool m_isUserBoxPressed;

    bool m_isPwdBoxSelected;
    bool m_isPwdBoxPressed;

    bool m_validUser; // probably this can be used
    int m_validUserIndex;

    bool m_errorMsgShow; // decide whether errorMsg should be shown
    int m_pressedCnt; // record number of time the login button is pressed

    std::string m_name;
    std::string m_password;

    void InputLogic(int charTyped, std::string &s);
    std::string MaskPwd(std::string s);

    bool IsTextSelected(sf::Text object);
    bool IsTextClicked(sf::Text object, sf::Mouse::Button button);

    bool IsBoxSelected(sf::RectangleShape object);
    bool IsBoxClicked(sf::RectangleShape object, sf::Mouse::Button button);

public:
    Login(std::shared_ptr<Context> &context);
    ~Login();

    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltaTime) override;
    void Draw() override;
};