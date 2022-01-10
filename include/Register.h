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

class Register : public Engine::State
{
private:
    std::shared_ptr<Context> m_context;
    sf::Text m_registerTitle;
    sf::Text m_registerButton;
    sf::Text m_returnMenuButton;
    sf::Text m_backButton;
    sf::Text m_userName;
    sf::Text m_UserPwd;
    sf::Text m_nameText;
    sf::Text m_pwdText;
    sf::Text m_errorMsg; // error message when there is already the same username

    sf::RectangleShape m_userNameBox;
    sf::RectangleShape m_pwdBox;

    sf::Texture m_ntuEmblem; // background image
    sf::Sprite m_ntuEmblemDraw; // texture to sprite

    bool m_isReturnMenuButtonSelected;
    bool m_isReturnMenuButtonPressed;

    bool m_isRegisterButtonSelected;
    bool m_isRegisterButtonPressed;

    bool m_isBackButtonSelected;
    bool m_isBackButtonPressed;

    bool m_isUserBoxSelected;
    bool m_isUserBoxPressed;

    bool m_isPwdBoxSelected;
    bool m_isPwdBoxPressed;

    bool m_validUser;
    bool m_showErrorMsg; // state whether the error message should be shown

    int m_validUserIndex;
    int m_allUser;


    std::string m_name;
    std::string m_password;    


    void InputLogic(int charTyped, std::string &s);
    std::string MaskPwd(std::string s);

    bool IsTextSelected(sf::Text object);
    bool IsTextClicked(sf::Text object, sf::Mouse::Button button);

    bool IsBoxSelected(sf::RectangleShape object);
    bool IsBoxClicked(sf::RectangleShape object, sf::Mouse::Button button);

public:
    Register(std::shared_ptr<Context> &context);
    ~Register();

    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltaTime) override;
    void Draw() override;
};