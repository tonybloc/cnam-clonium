#ifndef MANAGERCLONIUMGAME_H
#define MANAGERCLONIUMGAME_H

#include "../cloniumgame.h"
#include "managercloniumgrid.h"
#include "managercloniumplayer.h"
#include "../cloniumplayerabstract.h"
#include "../cloniumia.h"
#include "../cloniumplayer.h"


#define NUMBER_MAX_PLAYERS 4
#define NUMBER_MIN_PLAYERS 2

class ManagerCloniumGame
{
public:

    static ManagerCloniumGame& Instance();
    ~ManagerCloniumGame();

    // Make sure that game was correctly designed
    bool GameIsReady();

    // Add Player to Clonium Game
    void AddCloniumPlayer(CloniumPlayerAbstract* player);
    void RemoveCloniumPlayer(CloniumPlayerAbstract* player);

    Player* GetCurrentPlayer() const;
    Player* GetNextPlayer() const;
    std::vector<Player*>* GetPlayers() const;
    CloniumGrid* GetGrid() const;
    CloniumGame* GetGame() const;
    void SetGame(CloniumGame* game);
    uint GetNumberOfHuman() const;
    uint GetNumberOfIA() const ;
    uint GetNumberOfPlayer() const;
    uint GetMaximumOfPlayer() const;
    uint GetMinimumOfPlayer() const;
    void IncreaseValueOfPawn();

    void NextTurn();
    uint GetNumberOfTurn() const;

    // Initialize Game
    void InitializeCloniumGame(AvailableCloniumGrid shap);

    // Initialize Game by save file
    void InitializeCloniumGameFromSave(std::string filePath);
    // Save current Game
    bool SaveCloniumGame(std::string filePath);

private:
    static uint index_Player;
    static uint nb_Round;

    ManagerCloniumGame();
    static bool Predicate_FindCellContainersLinkedToPawnWithoutOwner(CellContainer& container);
    static bool Predicate_PlayerIsHuman(Player* p);
    static bool Predicate_PlayerIsIA(Player* p);

    ManagerCloniumGrid& GetManagerCloniumGrid() const;
    ManagerCloniumPlayer& GetManagerCloniumPlayer() const;


    //static std::string CloniumGameSavePath = ":/grids/clonium/Saves/CloniumSave.txt";
    CloniumGame* m_Game;
    static ManagerCloniumGame m_instance;

};

#endif // MANAGERCLONIUMGAME_H
