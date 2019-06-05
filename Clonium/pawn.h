#ifndef PAWN_H
#define PAWN_H

#include <stdlib.h>
#include <string>

class Pawn
{
public:
    /* Constructeurs */
    Pawn(unsigned int id, std::string color);
    Pawn(std::string color);

    /* Destructeur */
    virtual ~Pawn();

    /* Getters */
    inline unsigned int getId() const {return m_Id;}
    inline std::string getColor() const {return m_Color;}

    /* Setters */
    inline void setId(unsigned int id) {this->m_Id = id;}
    inline void setColor(std::string color) {this->m_Color = color; }

private:
    /* Variables private */
    unsigned int m_Id;
    std::string m_Color;
    unsigned int m_indexOfId;

    /* Methode private */
    inline void findNextId() { this->m_indexOfId += 1; setId(this->m_indexOfId);}

};

#endif // PAWN_H
