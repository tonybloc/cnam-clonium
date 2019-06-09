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
    Game(std::string title, uint min_player, uint max_player);
    Game(std::string title, uint min_player, uint max_player, Grid* gird);
    virtual ~Game() = 0;


    /* -- Accessor -- */

    /**
     * @brief GetMinumumOfPlayer : Get the minimum of player in game
     * @return
     */
    inline uint GetMinumumOfPlayer(void) const {return this->m_MinimumOfPlayers;}    
    inline uint GetMaximumOfPlayer(void) const {return this->m_MaximumOfPlayers;}    
    inline uint GetNumberOfPlayer(void) const  {return static_cast<uint>(m_Players->size());}
    inline std::string GetTitle(void) const {return this->m_Title;}    
    inline std::vector<Player*>* GetPlayers(void) const {return m_Players;}

    /* -- Virtual Method -- */

    virtual void AddPlayer(Player* player);    
    virtual void RemovePlayer(const Player* player);


    /* -- Pure Virtual Method -- */

    virtual Grid* GetGrid(void) const;    
    virtual void SetGrid(Grid* const grid);

protected:
    std::vector<Player*>* m_Players;
    Grid* m_Grid;
    uint m_nb_rounds;

private:
    inline void SetTitle(std::string title) {this->m_Title = title;}
    inline void SetMinumumOfPlayer(uint minimumOfPlayer) {m_MinimumOfPlayers = minimumOfPlayer;}
    inline void SetMaximumOfPlayer(uint maximumOfPlayer) {m_MaximumOfPlayers = maximumOfPlayer;}


    std::string m_Title;
    uint m_MinimumOfPlayers;
    uint m_MaximumOfPlayers;
};

#endif // GAME_H
