#ifndef GRID_H
#define GRID_H

#include <stdlib.h>
#include <string>
#include <vector>
#include "./cellcontainer.h"
#include "./pawn.h"

class Grid
{
public:
    Grid();
    virtual ~Grid() = 0;

    //virtual CellContainer& getContainerAt(uint index) = 0;
    virtual void FillContainer(CellContainer& container, Pawn& pawn) = 0;
    virtual void LoadListOfContainer(std::string filePath) = 0;

protected:
    std::vector<CellContainer> m_ListOfContainer;
};

#endif // GRID_H
