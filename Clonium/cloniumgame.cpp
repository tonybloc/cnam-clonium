#include "cloniumgame.h"
#include "cloniumgrid.h"

const int NB_MIN_PLAYERS = 2;
const int NB_MAX_PLAYERS = 4;

CloniumGame CloniumGame::m_instance=CloniumGame("Clonium",NB_MIN_PLAYERS,NB_MAX_PLAYERS,CloniumGrid(10,10));

CloniumGame::CloniumGame(std::string title, size_t min_player, size_t max_player, CloniumGrid grid):
    Game(title, min_player, max_player), m_Grid(grid)
{
}

CloniumGame::~CloniumGame()
{

}

CloniumGame& CloniumGame::Instance(){
    return m_instance;
}

void CloniumGame::startGame(void)
{

}
void CloniumGame::getGrid(void)
{

}
void CloniumGame::setGrid(Grid* g)
{

}
