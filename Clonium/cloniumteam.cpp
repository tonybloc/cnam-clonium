#include "cloniumteam.h"
#include "cloniumplayer.h"

CloniumTeam::CloniumTeam(unsigned int id, std::string name)
    :Team(id, name)
{

}

void CloniumTeam::calculateScoreTeam(){
    for (auto &player : m_ListOfPlayers)
    {
        //CloniumPlayer p = dynamic_cast<AbstractCloniumPlayer>(player);
        //m_TeamScore += p.m_Score;
    }
}
