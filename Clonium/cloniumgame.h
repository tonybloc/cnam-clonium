#ifndef CLONIUMGAME_H
#define CLONIUMGAME_H


#include "./game.h"
#include "./cloniumgrid.h"

class CloniumGame : Game
{
public:
    CloniumGame(std::string title, size_t min_player, size_t max_player, CloniumGrid grid);
    ~CloniumGame();

    void startGame(void);
    void getGrid(void);
    void setGrid(Grid* g);

private:
    CloniumGrid m_Grid;
};

#endif // CLONIUMGAME_H
