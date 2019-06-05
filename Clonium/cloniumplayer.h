#ifndef CLONIUMPLAYER_H
#define CLONIUMPLAYER_H

#include "./abstractcloniumplayer.h"

class CloniumPlayer : public AbstractCloniumPlayer
{
public:
    CloniumPlayer(unsigned int id, std::string name);

    Pawn CreatePawn();
};

#endif // CLONIUMPLAYER_H
