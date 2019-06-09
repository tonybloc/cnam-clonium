#ifndef PAWN_H
#define PAWN_H

#include <stdlib.h>
#include <string>

#include "player.h"

class Pawn
{
public:
    Pawn();
    Pawn(Player* player);
    virtual ~Pawn() = 0;

    inline void SetOwner(Player* player) {m_owner = player;}
    inline Player* GetOwner(void) const {return m_owner;}
private:
    Player* m_owner;


};

#endif // PAWN_H
