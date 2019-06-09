#ifndef PLAYER_H
#define PLAYER_H

#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>

class Player
{
public:
    Player(uint id, std::string name);
    virtual ~Player() = 0;

    inline uint GetId(void) const {return m_Id;}
    inline std::string GetName(void) const {return m_Name;}
    inline void SetName(std::string name) {m_Name = name;}

    friend bool operator==(Player const& a, Player const& b)
    {
        return (a.m_Id == b.m_Id && a.m_Name == b.m_Name);
    }
    friend std::ostream& operator<<(std::ostream& os, Player& p)
    {
        return os << p.m_Id << " " << p.m_Name;
    }
    friend std::istream& operator>>(std::istream& is, Player& p)
    {
        return is >> p.m_Id >> p.m_Name;
    }

protected:
    uint m_Id;
    std::string m_Name;

};

#endif // PLAYER_H
