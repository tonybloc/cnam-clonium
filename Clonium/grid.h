#ifndef GRID_H
#define GRID_H

#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "./cellcontainer.h"
#include "./pawn.h"

class Grid
{
public:
    Grid();
    Grid(const Grid* grid);
    virtual ~Grid() = 0;
};

#endif // GRID_H
