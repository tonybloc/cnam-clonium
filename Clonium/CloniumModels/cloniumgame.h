#ifndef CLONIUMGAME_H
#define CLONIUMGAME_H


#include "./game.h"
#include "./cloniumplayer.h"
#include "./cloniumgrid.h"


class CloniumGame : public Game
{
public:
    CloniumGame(std::string title, uint min_player, uint max_player);
    CloniumGame(std::string title, uint min_player, uint max_player, Grid* grid);
    ~CloniumGame();

    static CloniumGame& Instance();

    //void startGame(void);
    Grid* GetGrid(void) const;
    void SetGrid(Grid* const grid);

    void AddPlayer(Player* player);
};

#endif // CLONIUMGAME_H
