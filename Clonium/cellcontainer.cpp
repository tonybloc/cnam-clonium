#include "cellcontainer.h"

CellContainer::CellContainer()
{
    m_Pawn = nullptr;
}

CellContainer::CellContainer(Pawn* p):
    m_Pawn(p)
{}

CellContainer::~CellContainer(){
    delete m_Pawn;
}
