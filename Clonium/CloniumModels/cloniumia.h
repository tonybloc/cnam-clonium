#ifndef CLONIUMIA_H
#define CLONIUMIA_H

#include "cloniumplayerabstract.h"
#include "./pawn.h"

class CloniumIA : public CloniumPlayerAbstract
{
public:
    CloniumIA(uint id, std::string name);
    ~CloniumIA();

    friend bool operator==(CloniumIA const& a, CloniumIA const& b)
    {
        return (a.m_Id == b.m_Id && a.m_Name == b.m_Name);
    }
    friend std::ostream& operator<<(std::ostream& os, const CloniumIA& p)
    {
        return os << p.m_Id << " " << p.m_Name;
    }
    friend std::istream& operator>>(std::istream& is, CloniumIA& p)
    {
        return is >> p.m_Id >> p.m_Name;
    }

};

#endif // CLONIUMIA_H
