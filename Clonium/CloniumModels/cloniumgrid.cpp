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

        this->m_columns = static_cast<size_t>(result.count());
        this->m_rows = countRow;


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

    ShowGrid();
    return true;
}
