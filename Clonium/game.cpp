#include "game.h"

Game::Game(std::string title, uint min_player, uint max_player)
    : m_Grid(nullptr), m_Title(title), m_MinimumOfPlayers(min_player), m_MaximumOfPlayers(max_player)
{
    m_Players = new std::vector<Player*>();
}

Game::Game(std::string title, uint min_player, uint max_player, Grid* grid)
    : m_Grid(grid), m_Title(title), m_MinimumOfPlayers(min_player), m_MaximumOfPlayers(max_player)
{
    m_Players = new std::vector<Player*>();
}

Game::~Game(){
    //delete m_Grid;
    delete m_Players;
}

void Game::AddPlayer(Player* p)
{
    m_Players->push_back(p);
}
void Game::RemovePlayer(const Player* p)
{
    std::vector<Player*>::iterator it = std::find(m_Players->begin(), m_Players->end(), p);
    m_Players->erase(it);
}


Grid* Game::GetGrid() const
{
    return m_Grid;
}
void Game::SetGrid(Grid* const grid)
{
    m_Grid = grid;
}

