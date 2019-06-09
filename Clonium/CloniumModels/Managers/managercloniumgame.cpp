#include "managercloniumgame.h"

ManagerCloniumGame ManagerCloniumGame::m_instance = ManagerCloniumGame();

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

Player* ManagerCloniumGame::GetCurrentPlayer() {

}

Player* ManagerCloniumGame::GetNextPlayer() {

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
    return false;
}
ManagerCloniumGrid& ManagerCloniumGame::GetManagerCloniumGrid() const
{
    return ManagerCloniumGrid::Instance();
}
ManagerCloniumPlayer& ManagerCloniumGame::GetManagerCloniumPlayer() const
{
    return ManagerCloniumPlayer::Instance();
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

