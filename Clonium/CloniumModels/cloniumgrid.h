#ifndef CLONIUMGRID_H
#define CLONIUMGRID_H

#include "./squaregrid.h"
#include "CloniumModels/cloniumpawn.h"

#include <QFile>
#include <QString>

class CloniumGrid : public SquareGrid
{
public:
    CloniumGrid(std::string filepath);
    CloniumGrid(uint numberOfRow, uint numberOfColumn);

    ~CloniumGrid();

    void ShowGrid();

    bool LoadGridFromFile(std::string filepath);
    std::vector<CellContainer*>* GetAdjacent(const CellContainer* container);




};

#endif // CLONIUMGRID_H
