#include "squaregrid.h"

SquareGrid::SquareGrid(uint numberOfRow, uint numberOfColumn) :
    m_rows(numberOfRow), m_columns(numberOfColumn)
{    
    InitializeCellContainers(numberOfRow, numberOfColumn);
}

SquareGrid::~SquareGrid()
{
    this->ClearContainers();
    delete m_CellContainers;
}


void SquareGrid::InitializeCellContainers(uint nbRow, uint nbColumn)
{
    m_CellContainers = new std::vector<std::vector<CellContainer*>*>();

    for (uint row = 0; row < nbRow; row++)
    {
        std::vector<CellContainer*>* rowContainer = new std::vector<CellContainer*>();
        for(uint col = 0; col < nbColumn; col++)
        {
            rowContainer->push_back(new CellContainer());
        }
        m_CellContainers->push_back(rowContainer);
        //delete rowContainer;
    }
}
void SquareGrid::ShowGrid()
{
    std::vector<std::vector<CellContainer*>*>::iterator IteratorRow;
    std::vector<CellContainer*>::iterator IteratorColumn;

    for(IteratorRow = m_CellContainers->begin(); IteratorRow != m_CellContainers->end(); IteratorRow++)
    {
        std::string str = "{";
        for(IteratorColumn = (*IteratorRow)->begin(); IteratorColumn != (*IteratorRow)->end(); IteratorColumn++)
        {
            if( !(*IteratorColumn)->GetIsActive())
                str += "*";
            else if( (*IteratorColumn)->GetPawn() != nullptr)
                str += ((*IteratorColumn)->GetPawn()->GetOwner() != nullptr) ? "1" : "0";
            else
                str +=  "0, ";
        }
        str += "}";
        std::cout << str << std::endl;
    }
}

CellContainer* SquareGrid::GetElementAt(uint row, uint column)
{
    if(m_CellContainers != nullptr)
    {
        return m_CellContainers->at(row)->at(column);
    }
    return nullptr;
}

void SquareGrid::ClearContainers()
{
    std::vector<std::vector<CellContainer*>*>::iterator IteratorRow;
    std::vector<CellContainer*>::iterator IteratorColumn;

    for(IteratorRow = m_CellContainers->begin(); IteratorRow != m_CellContainers->end(); IteratorRow++)
    {
        for(IteratorColumn = (*IteratorRow)->begin(); IteratorColumn != (*IteratorRow)->end(); IteratorColumn++)
        {
            delete (*IteratorColumn);
        }
        (*IteratorRow)->clear();
    }
    delete m_CellContainers;
    m_CellContainers = new std::vector<std::vector<CellContainer*>*>();

}


