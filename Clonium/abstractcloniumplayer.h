#ifndef ABSTRACTCLONIUMPLAYER_H
#define ABSTRACTCLONIUMPLAYER_H

#include <string>

#include "./player.h"
#include "./pawn.h"

class AbstractCloniumPlayer : public Player
{
public:
    AbstractCloniumPlayer(unsigned int id, std::string name);

    void calculateScore();

    //virtual Pawn CreatePawn() =0;

    ~AbstractCloniumPlayer(){}

private:
    std::string m_Color;
    unsigned int m_Score;

};

#endif // ABSTRACTCLONIUMPLAYER_H
