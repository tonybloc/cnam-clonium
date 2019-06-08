#include "managercloniumgrid.h"

ManagerCloniumGrid ManagerCloniumGrid::m_instance = ManagerCloniumGrid();

ManagerCloniumGrid::ManagerCloniumGrid()
{
    m_GridFilePaths.insert(std::make_pair(BigRectangle, ":/Ressources/Clonium/GridShap/Ressources/Clonium/GridShap/BigRect.txt"));
    m_GridFilePaths.insert(std::make_pair(MediumRectangle, ":/Ressources/Clonium/GridShap/Ressources/Clonium/GridShap/MediumRect.txt"));
    m_GridFilePaths.insert(std::make_pair(SmallRectangle, ":/Ressources/Clonium/GridShap/Ressources/Clonium/GridShap/SmallRect.txt"));

}
ManagerCloniumGrid::~ManagerCloniumGrid ()
{

}

Grid* ManagerCloniumGrid::CreateCloniumGrid(AvailableCloniumGrid type)
{
    return new CloniumGrid(m_GridFilePaths[type]);
}

ManagerCloniumGrid& ManagerCloniumGrid::Instance()
{
    return m_instance;
}




