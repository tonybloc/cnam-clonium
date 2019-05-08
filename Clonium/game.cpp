#include "game.h"

Game::Game(std::string title, size_t min_player, size_t max_player) :
    m_Title(title), m_MinimumOfPlayers(min_player), m_MaximumOfPlayers(max_player)
{}

Game::~Game(){}

void Game::addPlayer(const Player& p)
{
    m_Players.push(p);
}

Player& Game::nextPlayer(void)
{
    if(m_Players.empty())
        throw std::out_of_range("ERREUR : Aucune joueur dans la partie");
    else {
        Player& p = m_Players.front();
        m_Players.pop();
        m_Players.push(p);
        return m_Players.back();
    }
}
