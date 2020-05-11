#include <iostream>
#include <vector>

using namespace std;


/**
 * @brief Stores basketball NBA/WNBA players
 * Class elements: ID (unsigned int), string name, string position, int height cm , int weight kg , DOB string
 * 
 * 
 */
class BasketballPlayer{

private:

    unsigned int ID;
    string name;
    string position;
    int height;
    int weight;
    string DOB;

public:

    friend class BasketballTeam; // Can access private elements of BasketballTeam
    
    //Empty Constructor
    BasketballPlayer();

    //Parametric Constructor
    BasketballPlayer(unsigned int ID_,
                     string name_,
                     string position_,
                     int height_,
                     int weight_,
                     string DOB_): 
                     ID(ID_), 
                     name(name_), 
                     position(position_), 
                     height(height_), 
                     weight(weight_),
                     DOB(DOB_){};     
    bool operator== ( BasketballPlayer & player_) const{
        bool isEqual = true;
        isEqual = isEqual && (ID == player_.ID);
        return isEqual;
    }

};

class BasketballTeam{

private: 
    vector<BasketballPlayer> players;
    vector<BasketballPlayer> inactive_players;

public:
    BasketballTeam();
    int getSize() const;
    void printRoster();

    void insert_new_player(BasketballPlayer player_){

        if(!players.size()){
           players.push_back(player_);
           return;
        }
        for(int i = 0; i < players.size(); i++){
            if(players[i] == player_){
                return;  
            }
        };
        players.push_back(player_);
    };

    void remove_player(unsigned int playerID){
        if(!players.size())
            return;
        bool foundPlayer = false;
        for(int i = 0; i < players.size(); i++){
            if(players[i].ID == playerID){
                foundPlayer = true;
            }
            if(foundPlayer && players.size() > 1){
                BasketballPlayer store = players[i];
                players[i] = players[i-1];
                players[i-1] = players[i];
            }
        };
        if(foundPlayer){
            players.pop_back();
            players.resize(players.size() - 1);
        }
    }   
    void activate_player(unsigned int playerID);
    void deactivate_player(unsigned int playerID);
};
