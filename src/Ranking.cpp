#include "../include/Ranking.h"
#include "../include/MainMenu.h"
#include<iostream>
#include <vector>
#include <numeric>      // std::iota
#include <algorithm>    // std::sort, std::stable_sort
#include <SFML/Window/Event.hpp>

#define topN 10

Ranking::Ranking(std::shared_ptr<Context> &context)
        : m_context(context),
          m_isReturnMenuButtonSelected(false), m_isReturnMenuButtonPressed(false)
{
}

Ranking::~Ranking()
{
}

bool Ranking::IsTextSelected(sf::Text object)
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


bool Ranking::IsTextClicked(sf::Text object, sf::Mouse::Button button)
{
    if (sf::Mouse::isButtonPressed(button) && IsTextSelected(object))
        return true;
    return false;
}

std::vector<int> Ranking::argsort(const std::vector<int> &v) 
{
    // initialize original index locations
    std::vector<int> idx(v.size());
    iota(idx.begin(), idx.end(), 0);

    // sort indexes based on comparing values in v
    // using std::stable_sort instead of std::sort
    // to avoid unnecessary index re-orderings
    // when v contains elements of equal values 
    stable_sort(idx.begin(), idx.end(),
                [&v](size_t i1, size_t i2) {return v[i1] < v[i2];});

    return idx;
}

void Ranking::getRankInfo(std::vector<std::string> &sortedNames, std::vector<std::string> &sortedWishes, std::vector<int> &sortedTimes)
{
    int allUserNum = (*m_context->m_userInfoVec).size();
    std::vector<int> allTimeUsed;
    for (int i = 0; i < allUserNum; i++)
        allTimeUsed.push_back((*m_context->m_userInfoVec)[i].TimeUsed);
    std::vector<int> sortedIdx = argsort(allTimeUsed);

    int n = (topN > 0 && topN <= allUserNum)? topN: allUserNum;
    for (int i = 0; i < n; i++)
    {
        if ((*m_context->m_userInfoVec)[sortedIdx[i]].WishStatus)
        {
            sortedNames.push_back((*m_context->m_userInfoVec)[sortedIdx[i]].User);
            sortedWishes.push_back((*m_context->m_userInfoVec)[sortedIdx[i]].Wish);
            sortedTimes.push_back((*m_context->m_userInfoVec)[sortedIdx[i]].TimeUsed);
        }
    }

    return;
}


void Ranking::Init()
{
    // Title
    m_rankingTitle.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_rankingTitle.setString(L"願望清單");
    m_rankingTitle.setFillColor(sf::Color::Black);
    m_rankingTitle.setOrigin(m_rankingTitle.getLocalBounds().width / 2,
                             m_rankingTitle.getLocalBounds().height / 2);
    m_rankingTitle.setPosition(m_context->m_window->getSize().x / 2 - 45.f,
                             m_context->m_window->getSize().y / 2 - 330.f);
    m_rankingTitle.setCharacterSize(54);
    
    // Sort
    std::vector<std::string> sortedNames;
    std::vector<std::string> sortedWishes;
    std::vector<int> sortedTimes;
    getRankInfo(sortedNames, sortedWishes, sortedTimes);
    int printN = (sortedNames.size() < topN)? sortedNames.size(): topN;
    for(int i = 0; i < printN; i++)
        std::cout << sortedNames[i] << ' ' << sortedWishes[i] << ' ' << sortedTimes[i] << '\n';
    

    // Ranks
    for (int i = 0; i < printN; i++)
    {
        sf::Text RankText;
        RankText.setFont(m_context->m_assets->GetFont(MAIN_FONT));
        RankText.setString(std::to_string(i + 1));
        RankText.setFillColor(sf::Color::Black);
        RankText.setOrigin(RankText.getLocalBounds().width / 2,
                             RankText.getLocalBounds().height / 2);
        RankText.setPosition(m_context->m_window->getSize().x / 2 - 300.f,
                             m_context->m_window->getSize().y / 2 - 230.f + i * 50.f);
        RankText.setCharacterSize(30);
        m_rankingRanks.push_back(RankText);
    }

    // Names
    for (int i = 0; i < printN; i++)
    {
        sf::Text NameText;
        NameText.setFont(m_context->m_assets->GetFont(MAIN_FONT));
        NameText.setString(sortedNames[i]);
        NameText.setFillColor(sf::Color::Black);
        NameText.setOrigin(NameText.getLocalBounds().width / 2,
                             NameText.getLocalBounds().height / 2);
        NameText.setPosition(m_context->m_window->getSize().x / 2 - 100.f,
                             m_context->m_window->getSize().y / 2 - 230.f + i * 50.f);
        NameText.setCharacterSize(30);
        m_rankingNames.push_back(NameText);
    }

    // Wishes
    for (int i = 0; i < printN; i++)
    {
        sf::Text WishText;
        WishText.setFont(m_context->m_assets->GetFont(MAIN_FONT));
        WishText.setString(sortedWishes[i]);
        WishText.setFillColor(sf::Color::Black);
        WishText.setOrigin(WishText.getLocalBounds().width / 2,
                             WishText.getLocalBounds().height / 2);
        WishText.setPosition(m_context->m_window->getSize().x / 2 + 100.f,
                             m_context->m_window->getSize().y / 2 - 230.f + i * 50.f);
        WishText.setCharacterSize(30);
        m_rankingWishes.push_back(WishText);
    }

    // Times
    for (int i = 0; i < printN; i++)
    {
        sf::Text TimeText;
        TimeText.setFont(m_context->m_assets->GetFont(MAIN_FONT));
        TimeText.setString(std::to_string(sortedTimes[i]));
        TimeText.setFillColor(sf::Color::Black);
        TimeText.setOrigin(TimeText.getLocalBounds().width / 2,
                             TimeText.getLocalBounds().height / 2);
        TimeText.setPosition(m_context->m_window->getSize().x / 2 + 300.f,
                             m_context->m_window->getSize().y / 2 - 230.f + i * 50.f);
        TimeText.setCharacterSize(30);
        m_rankingTimes.push_back(TimeText);
    }

    // Buttons
    m_returnMenuButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_returnMenuButton.setString(L"回到主選單");
    m_returnMenuButton.setFillColor(sf::Color::Black);
    m_returnMenuButton.setOrigin(m_returnMenuButton.getLocalBounds().width / 2,
                                 m_returnMenuButton.getLocalBounds().height / 2);
    m_returnMenuButton.setPosition(m_context->m_window->getSize().x / 2 - 45.f,
                                   m_context->m_window->getSize().y / 2 + 300.f);
    m_returnMenuButton.setCharacterSize(40);

    // load texture and sprite
    if (!m_bgImage.loadFromFile("assets/background/original_light_new.jpg"))// background image
        std::cout << "no data exists!";
    m_bgIamgeDraw.setTexture(m_bgImage);

}

void Ranking::ProcessInput()
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

void Ranking::Update(sf::Time deltaTime)
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

void Ranking::Draw()
{
    m_context->m_window->clear();
    m_context->m_window->draw(m_bgIamgeDraw);
    m_context->m_window->draw(m_rankingTitle);
    for (int i = 0; i < m_rankingNames.size(); i++)
    {
        m_context->m_window->draw(m_rankingRanks[i]);
        m_context->m_window->draw(m_rankingNames[i]);
        m_context->m_window->draw(m_rankingWishes[i]);
        m_context->m_window->draw(m_rankingTimes[i]);
    }
    m_context->m_window->draw(m_returnMenuButton);
    m_context->m_window->display();
}

