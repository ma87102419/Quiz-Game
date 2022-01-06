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
    sf::Text m_pwd;
    sf::Text m_nameText;
    sf::Text m_pwdText;

    sf::RectangleShape m_userNameBox;
    sf::RectangleShape m_pwdBox;

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
    int m_validUserIndex;
    int m_allUser;

    std::ifstream m_userInfoFile;

    std::string m_name;
    std::string m_password;

    std::string tmp_username;
    std::string tmp_password;
    bool tmp_complete_status;
    int tmp_total_ques_answered;
    int tmp_time_used;
    int tmp_life;
    int tmp_current_lv;
    bool tmp_account_status;
    std::string tmp_wish;
    bool tmp_wish_status;
    bool tmp_banned_status;
    int tmp_banned_time;

    std::string tmpUserArray[100] = {};
    std::string tmpPwdArray[100] = {};
    bool tmpCompleteStatusArray[100] = {};
    int tmpTotalQuesAnsweredArray[100] = {};
    int tmpTimeUsedArray[100] = {};
    int tmpLifeArray[100] = {};
    int tmpCurrentLvArray[100] = {};
    bool tmpAccountStatusArray[100] = {};
    std::string tmpWishArray[100] = {};
    bool tmpWishStatusArray[100] = {};
    bool tmpBannedStatusArray[100] = {};
    int tmpBannedTimeArray[100] = {};

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