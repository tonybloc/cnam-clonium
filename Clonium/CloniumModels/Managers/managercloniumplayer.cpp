#include "managercloniumplayer.h"

ManagerCloniumPlayer ManagerCloniumPlayer::m_instance = ManagerCloniumPlayer();

ManagerCloniumPlayer::ManagerCloniumPlayer()
{

}

ManagerCloniumPlayer::~ManagerCloniumPlayer()
{

}

ManagerCloniumPlayer& ManagerCloniumPlayer::Instance()
{
    return m_instance;
}
