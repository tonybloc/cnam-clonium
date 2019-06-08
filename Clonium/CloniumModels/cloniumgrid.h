#ifndef CLONIUMGRID_H
#define CLONIUMGRID_H

#include "./squaregrid.h"
#include "CloniumModels/cloniumpawn.h"

#include <QFile>
#include <QString>


typedef struct { uint row; uint column; } CellContainerIndex;

class CloniumGrid : public SquareGrid
{
public:
    CloniumGrid(std::string filepath);
    CloniumGrid(uint numberOfRow, uint numberOfColumn);

    ~CloniumGrid();

    void ShowGrid();

    bool LoadGridFromFile(std::string filepath);
    std::vector<CellContainerIndex*>* GetAdjacent(const CellContainer* container);
    std::vector<CellContainerIndex*>* GetCellContainerWithPawnWithoutOwner();




};

#endif // CLONIUMGRID_H
