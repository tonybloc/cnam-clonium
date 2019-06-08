#ifndef MANAGERGAMES_H
#define MANAGERGAMES_H

#include "CloniumModels/Managers/managercloniumgame.h"
#include "CloniumModels/cloniumplayer.h"

class ManagerGames
{
public:
    static ManagerGames& Instance();
    ~ManagerGames();

    ManagerCloniumGame& GetManagerCloniumGame() const;


private:
    ManagerGames();
    ManagerGames (const ManagerGames&);

    //static std::string CloniumGameSavePath = ":/grids/clonium/Saves/CloniumSave.txt";
    static ManagerGames m_instance;
};

#endif // MANAGERGAMES_H
