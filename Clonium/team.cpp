#include "team.h"
#include <vector>
#include <algorithm>

Team::Team(unsigned int id, std::string name)
    :m_TeamId(id), m_TeamName(name)
{

}

Team::~Team()
{

}

//void Team:: addPlayer(Player& p){
     //m_ListOfPlayers.push_back(p);
//}

//void Team::removePlayer(Player& p){
    /*if (m_ListOfPlayers.size() > 0){

        std::vector<Player>::iterator it = std::find(m_ListOfPlayers.begin(), m_ListOfPlayers.end(), p);

        if(it!=m_ListOfPlayers.end()){
            int index = std::distance(m_ListOfPlayers.begin(), it);
            m_ListOfPlayers.erase(m_ListOfPlayers.begin()+index);
        }
        else{
            printf("Impossible de supprimer le joueur");
        }
    }*/
//}

//Player& Team::getPlayerAt(unsigned int key){
   //return m_ListOfPlayers.at(key);
//}
