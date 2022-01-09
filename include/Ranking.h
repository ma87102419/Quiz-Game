#pragma once

#include <memory>
#include <vector>

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>

#include "State.h"
#include "Game.h"



class Ranking : public Engine::State
{
private:
    std::shared_ptr<Context> m_context;
    sf::Text m_rankingTitle;
    std::vector<sf::Text> m_rankingRanks;
    std::vector<sf::Text> m_rankingNames;
    std::vector<sf::Text> m_rankingWishes;
    std::vector<sf::Text> m_rankingTimes;
    sf::Text m_returnMenuButton;
    sf::Texture m_bgImage; // background image
    sf::Sprite m_bgIamgeDraw; // texture to sprite
    std::vector<int> argsort(const std::vector<int> &v); 
    void getRankInfo(std::vector<std::string> &sortedNames, std::vector<std::string> &sortedWishes, std::vector<int> &sortedTimes);

    bool m_isReturnMenuButtonSelected;
    bool m_isReturnMenuButtonPressed;

    bool IsTextSelected(sf::Text object);
    bool IsTextClicked(sf::Text object, sf::Mouse::Button button);

public:
    Ranking(std::shared_ptr<Context> &context);
    ~Ranking();

    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltaTime) override;
    void Draw() override;
};