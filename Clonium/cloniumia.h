#ifndef CLONIUMIA_H
#define CLONIUMIA_H

#include "./abstractcloniumplayer.h"
#include "./pawn.h"

class CloniumIA : public AbstractCloniumPlayer
{
public:
    CloniumIA(unsigned int id, std::string name);

    Pawn CreatePawn();
};

#endif // CLONIUMIA_H
