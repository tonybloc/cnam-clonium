#include "cloniumgrid.h"

CloniumGrid::CloniumGrid(std::string filepath)
    : SquareGrid (0,0)
{
    std::cout << "CLONIUMGRID" << std::endl;
    LoadGridFromFile(filepath);
}
CloniumGrid::CloniumGrid(uint numberOfRow, uint numberOfColumn)
    : SquareGrid (numberOfRow, numberOfColumn)
{
    std::cout << "CLONIUMGRID" << std::endl;
}

CloniumGrid::~CloniumGrid()
{
}
void CloniumGrid::ShowGrid()
{
    std::vector<std::vector<CellContainer*>*>::iterator IteratorRow;
    std::vector<CellContainer*>::iterator IteratorColumn;

    for(IteratorRow = m_CellContainers->begin(); IteratorRow != m_CellContainers->end(); IteratorRow++)
    {
        std::string str = "{";
        for(IteratorColumn = (*IteratorRow)->begin(); IteratorColumn != (*IteratorRow)->end(); IteratorColumn++)
        {
            CloniumPawn* pawn = dynamic_cast<CloniumPawn*>((*IteratorColumn)->GetPawn());
            if(!(*IteratorColumn)->GetIsActive())
                str += "*";
            else if(pawn != nullptr)
                str += std::to_string(pawn->GetLevel());
            else
                str +=  "0, ";
        }
        str += "}";
        std::cout << str << std::endl;
    }
}

bool CloniumGrid::LoadGridFromFile(std::string filePath)
{

    QFile file(QString::fromStdString(filePath));
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        std::cout << "Open file failed !" << std::endl;
        return false;
    }
    size_t countRow = 0;

    this->ClearContainers();
    delete m_CellContainers;
    m_CellContainers = new std::vector<std::vector<CellContainer*>*>();

    const std::string dot = ".";

    while (!file.atEnd())
    {
        countRow ++;
        QString line = file.readLine();
        QStringList result = line.split(' ');

        this->m_columns = static_cast<uint>(result.count());
        this->m_rows = static_cast<uint>(countRow);


        std::vector<CellContainer*>* containers = new std::vector<CellContainer*>();
        //format 1.. :
        // First : define if container should be active or not
        // Seconde : id of player
        // Third : level of pawn
        for (QString str : result)
        {
            CloniumPawn* pawn = new CloniumPawn();
            CellContainer* container = new CellContainer();
            container->SetIsActive(str.at(0) == '1');
            container->SetPawn(nullptr);

            if((str.at(1) == '.') && (str.at(2) != '.'))
            {
                pawn->SetLevel(static_cast<uint>(str.at(2).digitValue()));                
                pawn->SetOwner(nullptr);
                container->SetPawn(pawn);
            }
            containers->push_back(container);
            //delete pawn;
            //delete container;
        }
        m_CellContainers->push_back(containers);
    }

    //ShowGrid();
    return true;
}
std::vector<CellContainerIndex*>* CloniumGrid::GetAdjacent(const CellContainer* container)
{
    std::vector<CellContainerIndex*>* result = new std::vector<CellContainerIndex*>();
    CellContainerIndex* currentIndex = new CellContainerIndex();

    std::vector<std::vector<CellContainer*>*>::iterator RowIterator;
    std::vector<CellContainer*>::iterator ColumnIterator;

    uint row = 0;
    uint column = 0;

    bool isFind = false;

    for(RowIterator = m_CellContainers->begin(); RowIterator != m_CellContainers->end(); RowIterator++)
    {
        for(ColumnIterator = (*RowIterator)->begin(); ColumnIterator != (*RowIterator)->end(); ColumnIterator++)
        {
            if((*ColumnIterator) == container)
            {
                currentIndex->row = row;
                currentIndex->column = column;
                isFind = true;
            }
            column++;
        }

        if(isFind)
            break;

        row++;
        column = 0;
    }

    if(currentIndex->row > 0)
    {
        CellContainerIndex* top = new CellContainerIndex();
        top->row = currentIndex->row-1;
        top->column = currentIndex->column;
        result->push_back(top);
    }
    if(currentIndex->row < GetNumberOfRows()-1)
    {
        CellContainerIndex* bottom = new CellContainerIndex();
        bottom->row = currentIndex->row+1;
        bottom->column = currentIndex->column;
        result->push_back(bottom);
    }
    if(currentIndex->column > 0)
    {
        CellContainerIndex* left = new CellContainerIndex();
        left->row = currentIndex->row;
        left->column = currentIndex->column-1;
        result->push_back(left);
    }
    if(currentIndex->column < GetNumberOfColumns()-1)
    {
        CellContainerIndex* right = new CellContainerIndex();
        right->row = currentIndex->row;
        right->column = currentIndex->column+1;
        result->push_back(right);
    }

    return result;
}


std::vector<CellContainerIndex*>* CloniumGrid::GetCellContainerWithPawnWithoutOwner()
{
    std::vector<CellContainerIndex*>* result = new std::vector<CellContainerIndex*>();

    std::vector<std::vector<CellContainer*>*>::iterator RowIterator;
    std::vector<CellContainer*>::iterator ColumnIterator;

    uint row = 0;
    uint column = 0;

    for(RowIterator = m_CellContainers->begin(); RowIterator != m_CellContainers->end(); RowIterator++)
    {
        for(ColumnIterator = (*RowIterator)->begin(); ColumnIterator != (*RowIterator)->end(); ColumnIterator++)
        {
            if(const CloniumPawn* pawn = dynamic_cast<CloniumPawn*>((*ColumnIterator)->GetPawn()))
            {
                if(pawn->GetOwner() == nullptr)
                {
                    CellContainerIndex* index = new CellContainerIndex();
                    index->row = row;
                    index->column = column;
                    result->push_back(index);
                }
            }
            column++;
        }
        row++;
        column = 0;
    }
    return result;
}

void CloniumGrid::IncreaseValueOfPawn(const CellContainerIndex* index)
{
    /*
    if(GetElementAt(index->row, index->column) != nullptr)
    {
        GetElementAt(index->row, index->column)->SetPawn(new)
    }
    */
}
