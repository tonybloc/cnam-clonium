#include "managercloniumgame.h"

ManagerCloniumGame ManagerCloniumGame::m_instance = ManagerCloniumGame();
uint ManagerCloniumGame::index_Player=0;
uint ManagerCloniumGame::nb_Round=0;

ManagerCloniumGame::ManagerCloniumGame()
{
    m_Game = new CloniumGame("Clonium", NUMBER_MIN_PLAYERS, NUMBER_MAX_PLAYERS);
}

ManagerCloniumGame::~ManagerCloniumGame ()
{
    delete m_Game;
}


CloniumGame* ManagerCloniumGame::GetGame() const
{
    return m_Game;
}
void ManagerCloniumGame::SetGame(CloniumGame* game)
{
    m_Game = game;
}

bool ManagerCloniumGame::GameIsReady()
{
    // make sure that number of player is enought
    if( (m_Game != nullptr) && (m_Game->GetNumberOfPlayer() <= NUMBER_MAX_PLAYERS) && (m_Game->GetNumberOfPlayer() >= NUMBER_MIN_PLAYERS))
    {
        // make sure that grid was designed
        if(m_Game->GetGrid() != nullptr)
            return true;
    }
    return false;
}

void ManagerCloniumGame::AddCloniumPlayer(CloniumPlayerAbstract* player)
{
    // Add new player in game.
    if(this->m_Game != nullptr)
    {
        this->m_Game->AddPlayer(player);
    }
}
void ManagerCloniumGame::RemoveCloniumPlayer(CloniumPlayerAbstract *player){
    if(m_Game != nullptr)
    {
        this->m_Game->RemovePlayer(player);
    }

}
std::vector<Player*>* ManagerCloniumGame::GetPlayers() const
{
    return m_Game->GetPlayers();
}


std::vector<CellContainerIndex*>* ManagerCloniumGame::GetPawnOwnedByPlayer(const Player* player) const
{
    std::vector<CellContainerIndex*>* result = new std::vector<CellContainerIndex*>();
    std::vector<std::vector<CellContainer*>*>* CellsContainers = this->GetGrid()->GetCellsContainers();
    std::vector<std::vector<CellContainer*>*>::iterator RowIterator;
    std::vector<CellContainer*>::iterator ColumnIterator;

    uint rows = 0;
    uint column = 0;
    for(RowIterator = CellsContainers->begin(); RowIterator != CellsContainers->end(); RowIterator++ )
    {
        for(ColumnIterator = (*RowIterator)->begin(); ColumnIterator != (*RowIterator)->end(); ColumnIterator++)
        {
            if((*ColumnIterator)->GetPawn() != nullptr)
            {
                if((*ColumnIterator)->GetPawn()->GetOwner() != nullptr)
                {
                    if((*ColumnIterator)->GetPawn()->GetOwner() == player)
                    {
                        CellContainerIndex* index = new CellContainerIndex();
                        index->row = rows;
                        index->column = column;
                        result->push_back(index);
                    }
                }
            }
            column++;
        }
        rows++;
        column = 0;
    }
    return result;
}


Player* ManagerCloniumGame::GetCurrentPlayer() const {
    if(GetPlayers()->size() != 0)
        return GetPlayers()->at(index_Player);
    else
        return nullptr;
}

Player* ManagerCloniumGame::GetNextPlayer() const{

    if(GetPlayers()->size() != 0)
    {
        index_Player = ((index_Player+1) % GetNumberOfPlayer());

        Player* player = GetPlayers()->at(index_Player);
        std::cout << "Player Next :" << player->GetId() << std::endl;
        return player;
        /*
        while ((GetPawnOwnedByPlayer(player)->size() == 0)) {
            GetNextPlayer();
        }*/
        //return GetPlayers()->at(index_Player);
    }
    else
    {
        return nullptr;
    }
}

CloniumGrid* ManagerCloniumGame::GetGrid() const
{
    if(m_Game != nullptr)
    {
        return dynamic_cast<CloniumGrid*>(m_Game->GetGrid());
    }
    return nullptr;
}
uint ManagerCloniumGame::GetNumberOfHuman() const
{
    if(m_Game != nullptr)
    {
        long value = std::count_if(m_Game->GetPlayers()->begin(), m_Game->GetPlayers()->end(), Predicate_PlayerIsHuman);
        return static_cast<uint>(value);
    }
    return 0;

}
uint ManagerCloniumGame::GetNumberOfIA() const{
    if(m_Game != nullptr)
    {
        long value = std::count_if(m_Game->GetPlayers()->begin(), m_Game->GetPlayers()->end(), Predicate_PlayerIsIA);
        return static_cast<uint>(value);
    }
    return 0;
}

uint ManagerCloniumGame::GetNumberOfPlayer() const{
    return GetNumberOfIA() + GetNumberOfHuman();
}

uint ManagerCloniumGame::GetMaximumOfPlayer() const
{
    return m_Game->GetMaximumOfPlayer();
}
uint ManagerCloniumGame::GetMinimumOfPlayer() const
{
    return m_Game->GetMinumumOfPlayer();
}
void ManagerCloniumGame::InitializeCloniumGame(AvailableCloniumGrid shap)
{
    if(this->m_Game != nullptr)
    {
        // Update grid of game
        this->m_Game->SetGrid(GetManagerCloniumGrid().CreateCloniumGrid(shap));
    }
}
void ManagerCloniumGame::InitializeCloniumGameFromSave(std::string filePath)
{

}
bool ManagerCloniumGame::SaveCloniumGame(std::string filePath)
{

    QFile file(QString::fromStdString(filePath));
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        std::cout << "Open file failed !" << std::endl;
        return false;
    }
    QTextStream out(&file);

    std::vector<Player*>* players = GetPlayers();
    std::vector<std::vector<CellContainer*>*>* container = GetGrid()->GetCellsContainers();

    std::vector<Player*>::iterator playerIterator;
    std::vector<std::vector<CellContainer*>*>::iterator RowIterator;
    std::vector<CellContainer*>::iterator ColumnIterator;

    out << "#GAME";
    out << QString::fromStdString(GetGame()->GetTitle()) << GetGame()->GetNumberOfPlayer() << GetGame()->GetMaximumOfPlayer() << GetGame()->GetMinumumOfPlayer();
    out << "#PLAYER";
    for(playerIterator = players->begin(); playerIterator != players->end(); playerIterator++)
    {
        out << (*playerIterator)->GetId() << " " << QString::fromStdString((*playerIterator)->GetName()) << endl;;
    }
    out << "#GRID";
    for(RowIterator = container->begin(); RowIterator != container->end(); RowIterator++)
    {
        QString str = "";
        for(ColumnIterator = (*RowIterator)->begin(); ColumnIterator != (*RowIterator)->end(); ColumnIterator++)
        {
            str.append((*ColumnIterator)->GetIsActive());

            if((*ColumnIterator)->GetPawn() != nullptr)
            {
                if((*ColumnIterator)->GetPawn()->GetOwner() != nullptr)
                {
                    str.append((*ColumnIterator)->GetPawn()->GetOwner()->GetId());
                }
                else {
                    str.append(".");
                }
                str.append(dynamic_cast<CloniumPawn*>((*ColumnIterator)->GetPawn())->GetLevel());
            }
            else {
                str.append(".");
            }

            str.append(" ");
        }
        out << str << endl;
    }

    return true;
}
ManagerCloniumGrid& ManagerCloniumGame::GetManagerCloniumGrid() const
{
    return ManagerCloniumGrid::Instance();
}
ManagerCloniumPlayer& ManagerCloniumGame::GetManagerCloniumPlayer() const
{
    return ManagerCloniumPlayer::Instance();
}

void ManagerCloniumGame::NextTurn(){
    nb_Round++;

}

uint ManagerCloniumGame::GetNumberOfTurn() const{
    return nb_Round;
}


ManagerCloniumGame& ManagerCloniumGame::Instance()
{
    return m_instance;
}

// -- Predicates -- //

bool ManagerCloniumGame::Predicate_PlayerIsHuman(Player* p)
{
    if(dynamic_cast<CloniumPlayer*>(p))
        return true;

    return false;
}
bool ManagerCloniumGame::Predicate_PlayerIsIA(Player* p)
{
    if(dynamic_cast<CloniumIA*>(p))
        return true;

    return false;
}

