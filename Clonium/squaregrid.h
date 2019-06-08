#ifndef SQUAREGRID_H
#define SQUAREGRID_H

#include "stdlib.h"
#include "./grid.h"

class SquareGrid : public Grid
{
public:
    SquareGrid(uint rows, uint columns);
    virtual ~SquareGrid() = 0;

    virtual void ShowGrid();

    void InitializeCellContainers(uint row, uint column);
    inline std::vector<std::vector<CellContainer*>*>* GetCellsContainers() const {return m_CellContainers;}
    inline uint GetNumberOfColumns(void) const {return this->m_columns;}
    inline uint GetNumberOfRows(void) const {return this->m_rows; }
    CellContainer* GetElementAt(uint row, uint column);
    void ClearContainers(void);

protected:
    std::vector<std::vector<CellContainer*>*>* m_CellContainers;
    uint m_rows;
    uint m_columns;
};

#endif // SQUAREGRID_H
