#ifndef TEAM_H
#define TEAM_H

#include <string>
#include <vector>

#include "./player.h"

class Team
{
public:
    Team(unsigned int id, std::string name);
    virtual ~Team() =0;

    virtual void addPlayer(Player& p);
    virtual void removePlayer(Player& p);
    virtual Player& getPlayerAt(unsigned int key);

private:
    unsigned int m_TeamId;
    std::string m_TeamName;
    std::string m_TeamColor;
protected:
    std::vector<Player> m_ListOfPlayers;

};

#endif // TEAM_H
