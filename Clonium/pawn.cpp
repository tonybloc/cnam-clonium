#include "pawn.h"

Pawn::Pawn(unsigned int id, std::string color) :
    m_Id(id),
    m_Color(color)
{

}
Pawn::Pawn(std::string color) :
    m_Color(color)
{
    findNextId();
}

Pawn::~Pawn()
{

}

