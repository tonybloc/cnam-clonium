#ifndef MANAGERCLONIUMGRID_H
#define MANAGERCLONIUMGRID_H

#include "../cloniumgrid.h"
#include <map>
#include <QFile>
#include <QString>
#include <QIODevice>

enum AvailableCloniumGrid { BigRectangle = 0, MediumRectangle = 1, SmallRectangle = 2 };


class ManagerCloniumGrid
{
public:
    static ManagerCloniumGrid& Instance();
    ~ManagerCloniumGrid();

    Grid* CreateCloniumGrid(AvailableCloniumGrid type);

private:
    ManagerCloniumGrid();

    static ManagerCloniumGrid m_instance;
    std::map<AvailableCloniumGrid, std::string> m_GridFilePaths;
};


#endif // MANAGERCLONIUMGRID_H
