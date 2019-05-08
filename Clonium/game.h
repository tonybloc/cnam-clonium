#ifndef GAME_H
#define GAME_H

#include <QString>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <algorithm>

#include "./player.h"
#include "./grid.h"

class Game
{
public:
    Game(std::string title, size_t min_player, size_t max_player);
    virtual ~Game() = 0;

    void addPlayer(const Player& p);
    Player& nextPlayer(void);

    inline size_t getMinumumOfPlayer(void) const {return this->m_MinimumOfPlayers;}
    inline size_t getMaximumOfPlayer(void) const {return this->m_MaximumOfPlayers;}
    inline size_t getNumberOfPlayer(void) const  {return m_Players.size();}
    inline std::string getTitle(void) const {return this->m_Title;}
    inline void setTitle(std::string title) {this->m_Title = title;}


    virtual void startGame(void) = 0;
    virtual void getGrid(void) = 0;
    virtual void setGrid(Grid* g) = 0;

private:
    std::string m_Title;
    std::queue<Player> m_Players;
    size_t m_MinimumOfPlayers;
    size_t m_MaximumOfPlayers;
};

#endif // GAME_H
