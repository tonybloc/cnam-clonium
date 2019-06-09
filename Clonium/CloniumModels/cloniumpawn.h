#ifndef CLONIUMPAWN_H
#define CLONIUMPAWN_H

#include "pawn.h"

class CloniumPawn : public Pawn
{
public:
    CloniumPawn();
    CloniumPawn(uint level);
    CloniumPawn(Player* player, uint level);
    ~CloniumPawn();

    inline uint GetLevel() const {return m_level;}
    inline void SetLevel(uint level) {m_level = level;}
    inline bool IncreaseLevel()
    {
        SetLevel(m_level+1);
        if(m_level >= SplitLevel)
        {
            SetLevel(0);
            return true;
        }
        return false;
    };

    static uint const SplitLevel = 4;

private:
    uint m_level;

};

#endif // CLONIUMPAWN_H
