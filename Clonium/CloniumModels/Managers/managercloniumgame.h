#ifndef MANAGERCLONIUMGAME_H
#define MANAGERCLONIUMGAME_H

#include "../cloniumgame.h"
#include "managercloniumgrid.h"
#include "managercloniumplayer.h"
#include "../cloniumplayerabstract.h"
#include "../cloniumia.h"
#include "../cloniumplayer.h"
#include <QTextStream>

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
    // Remove player in game
    void RemoveCloniumPlayer(CloniumPlayerAbstract* player);

    // Get current player of game
    Player* GetCurrentPlayer() const;
    // Get next player of game
    Player* GetNextPlayer() const;
    // Get player
    std::vector<Player*>* GetPlayers() const;
    // Get list of pawn that owned by player
    std::vector<CellContainerIndex*>* GetPawnOwnedByPlayer(const Player* player) const;
    // Get current grid
    CloniumGrid* GetGrid() const;
    // Get current game;
    CloniumGame* GetGame() const;

    // Start game (not used)
    void SetGame(CloniumGame* game);
    // GetNumber of humain
    uint GetNumberOfHuman() const;
    // Get number of IA in game
    uint GetNumberOfIA() const ;
    // Get number of player in game
    uint GetNumberOfPlayer() const;
    // Get Maximum of player
    uint GetMaximumOfPlayer() const;
    // Get Minimum of player
    uint GetMinimumOfPlayer() const;


    //void IncreaseValueOfPawn();

    // Incremente counter of turn
    void NextTurn();

    // Get Number of turn
    uint GetNumberOfTurn() const;

    // Initialize Game
    void InitializeCloniumGame(AvailableCloniumGrid shap);

    // Initialize Game by save file
    void InitializeCloniumGameFromSave(std::string filePath);

    // Save current Game
    bool SaveCloniumGame(std::string filePath);


    const std::string savefilepath = ":/Ressources/Clonium/Save/Ressources/Clonium/Save/clonium_save.txt";

private:
    static uint index_Player;
    static uint nb_Round;

    ManagerCloniumGame();

    // Predicate
    static bool Predicate_FindCellContainersLinkedToPawnWithoutOwner(CellContainer& container);
    static bool Predicate_PlayerIsHuman(Player* p);
    static bool Predicate_PlayerIsIA(Player* p);

    ManagerCloniumGrid& GetManagerCloniumGrid() const;
    ManagerCloniumPlayer& GetManagerCloniumPlayer() const;


    CloniumGame* m_Game;
    static ManagerCloniumGame m_instance;

};

#endif // MANAGERCLONIUMGAME_H
