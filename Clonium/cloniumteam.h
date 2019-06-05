#ifndef CLONIUMTEAM_H
#define CLONIUMTEAM_H

#include "team.h"

class CloniumTeam : public Team
{
public:
    CloniumTeam(unsigned int id, std::string name);

    void calculateScoreTeam();
private:
    unsigned int m_TeamScore;
};

#endif // CLONIUMTEAM_H
