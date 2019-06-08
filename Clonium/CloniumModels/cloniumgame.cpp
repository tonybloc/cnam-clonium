#include "cloniumgame.h"
#include "cloniumgrid.h"

CloniumGame::CloniumGame(std::string title, uint min_player, uint max_player)
    : Game(title, min_player, max_player)
{
    this->m_Grid = new CloniumGrid(0,0);
}

CloniumGame::CloniumGame(std::string title, uint min_player, uint max_player, Grid* grid)
    : Game(title, min_player, max_player)
{
    if(dynamic_cast<CloniumGrid*>(grid))
        this->SetGrid(grid);
    else
        this->SetGrid(new CloniumGrid(0,0));
}

CloniumGame::~CloniumGame()
{

}

Grid* CloniumGame::GetGrid() const
{
    dynamic_cast<CloniumGrid*>(m_Grid)->ShowGrid();
    return this->m_Grid;
}
void CloniumGame::SetGrid(Grid* const grid)
{
    if(dynamic_cast<CloniumGrid*>(grid))
    {
        m_Grid = grid;
    }
}

void CloniumGame::AddPlayer(Player* p)
{
    if(dynamic_cast<CloniumPlayerAbstract*>(p))
    {
         m_Players->push_back(p);
         std::cout << p << std::endl;
    }
    else
    {
        std::cout << p << std::endl;
    }
}
