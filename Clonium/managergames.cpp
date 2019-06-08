#include "managergames.h"

ManagerGames ManagerGames::m_instance = ManagerGames();

ManagerGames::ManagerGames()
{
}

ManagerGames::ManagerGames (const ManagerGames&)
{
}

ManagerGames::~ManagerGames ()
{
}

ManagerGames& ManagerGames::Instance()
{
    return m_instance;
}

ManagerCloniumGame& ManagerGames::GetManagerCloniumGame() const
{
    return ManagerCloniumGame::Instance();
}
