#include "cloniumpawn.h"

CloniumPawn::CloniumPawn()
    : Pawn()
{
}


CloniumPawn::CloniumPawn(uint level)
    : Pawn(), m_level(level)
{

}
CloniumPawn::CloniumPawn(Player* player, uint level)
    : Pawn(player), m_level(level)
{

}

CloniumPawn::~CloniumPawn(){}
