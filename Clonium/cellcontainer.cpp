#include "cellcontainer.h"

uint CellContainer::count = 0;

CellContainer::CellContainer()
{    
    CellContainer::count++;
    m_Pawn = nullptr;
    m_Id = count;
}

CellContainer::CellContainer(Pawn* p):
    m_Pawn(p)
{
    CellContainer::count++;
    m_Id = count;
}

CellContainer::~CellContainer(){
    delete m_Pawn;
    count--;
}
