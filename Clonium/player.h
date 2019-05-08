#ifndef PLAYER_H
#define PLAYER_H

#include <stdlib.h>
#include <string>
#include <vector>

#include "./pawn.h"

class Player
{
public:
    Player(unsigned int id, std::string name);
    virtual ~Player();

    void addPawn(Pawn& p);
    void removePawn(Pawn& p);


private:
    std::vector<Pawn> m_ListOfPawns;
    unsigned int m_Id;
    std::string m_Name;
};

#endif // PLAYER_H
