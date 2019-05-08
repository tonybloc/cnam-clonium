#ifndef SQUAREGRID_H
#define SQUAREGRID_H

#include "stdlib.h"
#include "./grid.h"

class SquareGrid : Grid
{
public:
    SquareGrid(uint numberOfRow, uint numberOfColumn);
    virtual ~SquareGrid() = 0;

    inline uint getNumberOfColumn(void) const {return this->m_NumberOfColumn;}
    inline uint getNumberOfRow(void) const {return this->m_NumberOfRow; }

    //CellContainer& getContainerAt(uint index);
    void FillContainer(CellContainer& container, Pawn& pawn);
    void LoadListOfContainer(std::string filePath);

    uint ConvertIndexToRowAndColumn(uint index);
    uint ConvertRowAndColumnToIndex(uint row, uint column);

private:
    uint m_NumberOfRow;
    uint m_NumberOfColumn;
};

#endif // SQUAREGRID_H
