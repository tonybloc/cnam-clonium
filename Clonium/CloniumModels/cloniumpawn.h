#ifndef CLONIUMPAWN_H
#define CLONIUMPAWN_H

#include "pawn.h"

class CloniumPawn : public Pawn
{
public:
    CloniumPawn();
    CloniumPawn(uint level);
    ~CloniumPawn();

    inline uint GetLevel() const {return m_level;}
    inline void SetLevel(uint level) {m_level = level;}
    inline uint IncreaseLevel()
    {
        m_level = ((m_level+1) % SplitLevel)+1;
        return GetLevel();
    };

    static uint const SplitLevel = 4;

private:
    uint m_level;

};

#endif // CLONIUMPAWN_H
