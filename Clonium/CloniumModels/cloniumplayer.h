#ifndef CLONIUMPLAYER_H
#define CLONIUMPLAYER_H

#include "cloniumplayerabstract.h"

class CloniumPlayer : public CloniumPlayerAbstract
{
public:
    CloniumPlayer(uint id, std::string name);
    ~CloniumPlayer();

    friend bool operator==(CloniumPlayer const& a, CloniumPlayer const& b)
    {
        return (a.m_Id == b.m_Id && a.m_Name == b.m_Name);
    }
    friend std::ostream& operator<<(std::ostream& os, const CloniumPlayer& p)
    {
        return os << p.m_Id << " " << p.m_Name;
    }
    friend std::istream& operator>>(std::istream& is, CloniumPlayer& p)
    {
        return is >> p.m_Id >> p.m_Name;
    }
};

#endif // CLONIUMPLAYER_H
