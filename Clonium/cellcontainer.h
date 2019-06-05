#ifndef CELLCONTAINER_H
#define CELLCONTAINER_H

#include "./pawn.h"

class CellContainer
{
public:

    CellContainer();
    CellContainer(Pawn* p);
    virtual ~CellContainer();

    void GetPawn(void);
    void RemovePawn(void);

private:
    Pawn* m_Pawn;

};

#endif // CELLCONTAINER_H
