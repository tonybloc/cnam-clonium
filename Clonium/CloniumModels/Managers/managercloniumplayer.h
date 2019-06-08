#ifndef MANAGERCLONIUMPLAYER_H
#define MANAGERCLONIUMPLAYER_H

#include "CloniumModels/cloniumplayer.h"
#include "CloniumModels/cloniumpawn.h"

class ManagerCloniumPlayer
{
public:
    static ManagerCloniumPlayer& Instance();
    ~ManagerCloniumPlayer();

private:
    ManagerCloniumPlayer();
    ManagerCloniumPlayer (const ManagerCloniumPlayer&);



    static ManagerCloniumPlayer m_instance;
};

#endif // MANAGERCLONIUMPLAYER_H
