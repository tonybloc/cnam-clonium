#ifndef CLONIUMGAME_H
#define CLONIUMGAME_H


#include "./game.h"
#include "./cloniumgrid.h"

class CloniumGame : public Game
{
public:
    CloniumGame(std::string title, size_t min_player, size_t max_player, CloniumGrid grid);
    ~CloniumGame();

    static CloniumGame& Instance();

    void startGame(void);
    void getGrid(void);
    void setGrid(Grid* g);

private:
    CloniumGrid m_Grid;
    static CloniumGame m_instance;
};

#endif // CLONIUMGAME_H
