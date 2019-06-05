#include "player.h"
#include <vector>
#include <algorithm>

Player::Player(unsigned int id, std::string name):
    m_Id(id),
    m_Name(name)
{

}

Player::~Player()
{

}

void Player::addPawn(Pawn &p){
    m_ListOfPawns.push_back(p);
}

void Player::removePawn(Pawn &p){

    /*if (m_ListOfPawns.size() > 0){

        std::vector<Pawn>::iterator it = std::find(m_ListOfPawns.begin(), m_ListOfPawns.end(), p);

        if(it!=m_ListOfPawns.end()){
            int index = std::distance(m_ListOfPawns.begin(), it);
            m_ListOfPawns.erase(m_ListOfPawns.begin()+index);
        }
        else{
            printf("Impossible de supprimer le pion");
        }
    }*/
}


Pawn& Player::getPawnAt(unsigned int key){
    return m_ListOfPawns.at(key);
}


