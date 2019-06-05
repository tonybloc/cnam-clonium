#include "cellcontainer.h"

CellContainer::CellContainer()
{
    m_Pawn = NULL;
}
CellContainer::CellContainer(Pawn* p):
    m_Pawn(p)
{

}
CellContainer::~CellContainer(){

}
