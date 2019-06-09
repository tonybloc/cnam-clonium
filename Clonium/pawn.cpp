#include "pawn.h"

Pawn::Pawn()
{
    m_owner = nullptr;
}

Pawn::Pawn(Player* player)
{
    player = nullptr;
}


Pawn::~Pawn()
{
    //m_owner = new(nullptr);
}

