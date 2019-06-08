#ifndef CELLCONTAINER_H
#define CELLCONTAINER_H

#include "./pawn.h"

class CellContainer
{
public:

    CellContainer();
    CellContainer(Pawn* pawn);
    CellContainer(const CellContainer* container);
    ~CellContainer();

    inline uint GetID(void) const {return m_Id;}
    inline Pawn* GetPawn(void) const {return m_Pawn;}
    inline void SetPawn(Pawn* const pawn) {m_Pawn = pawn;}
    inline bool GetIsActive(void) const {return m_isActive;}
    inline void SetIsActive(bool value) {m_isActive = value;}

    friend bool operator==(CellContainer const& a, CellContainer const& b)
    {
        return (a.m_Id == b.m_Id);
    }

private:
    static uint count;

    uint m_Id;
    bool m_isActive;
    Pawn* m_Pawn;

};

#endif // CELLCONTAINER_H
