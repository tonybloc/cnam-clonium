#ifndef CLONIUMPLAYERABSTRACT_H
#define CLONIUMPLAYERABSTRACT_H

#include "player.h"

class CloniumPlayerAbstract : public Player
{
public:
    CloniumPlayerAbstract(uint id, std::string name);
    virtual ~CloniumPlayerAbstract() = 0;

    friend bool operator==(CloniumPlayerAbstract const& a, CloniumPlayerAbstract const& b)
    {
        return (a.m_Id == b.m_Id && a.m_Name == b.m_Name);
    }
    friend std::ostream& operator<<(std::ostream& os, const CloniumPlayerAbstract& p)
    {
        return os << p.m_Id << " " << p.m_Name;
    }
    friend std::istream& operator>>(std::istream& is, CloniumPlayerAbstract& p)
    {
        return is >> p.m_Id >> p.m_Name;
    }
};

#endif // CLONIUMPLAYERABSTRACT_H
