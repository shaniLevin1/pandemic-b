#include"Player.hpp"
#include"Board.hpp"
#include"City.hpp"
#include<iterator>
#include<map>
using namespace std;
namespace pandemic{
    
    Player& Player::drive(City city){ 
        if(Board::city_connected(Player::city,city)){
            Player::city=city;
        }
        else{
            throw "Execption-> there is no cinnection between the cities";
        }
        return *this;
    }
    Player& Player::fly_direct(City city){
        if(Player::cards.count(city)==1){ //the player has the card of the city 
            Player::city=city;
            cards.erase(city);
        }
        else{
            throw"Execption-> dont have the card of the city";
        }
        return *this;
    }
    Player& Player::fly_charter(City city){
        if(Player::cards.count(Player::city)==1){ //the player has the card of the city 
            Player::city=city;
            cards.erase(Player::city);
        }
        else{
            throw"Execption-> dont have the card of the city";
        }
        return *this;
    }
    Player& Player::fly_shuttle(City city){ //need to check if we need to drop card from the set
        if(Board::city_research_stations(Player::city)==1&&Board::city_research_stations(city)==1){
            Player::city=city;
        }
        else{
            throw"Execption-> there is no research station in one of the cities";
        }
        return *this;
    }
    Player& Player::build(){
        if(Player::cards.count(Player::city)==1){
            if(!Board::city_research_stations(Player::city)){ //there is no research_stations in this city
                Board::update_research_station(Player::city,1);
                cards.erase(Player::city);
            }
            // else return *this;
        }  
        else{
            throw"Execption-> dont have the card of the city";
        }  
     return *this;
    }
    Player& Player::discover_cure(Color color){
        if(!Board::find_madication(color)){ //if the madication for this color did not found yet
            if(Board::city_research_stations(Player::city)){
                int count=0; 
                bool flag=false;
                for (auto card : Player::cards){
                    if(Board::color_of_city(card)==color){
                        count++;
                    }
                }
                if(count>5){
                    flag=true;
                    count=0;
                for (auto card : Player::cards){
                        if(count<5){
                            if(Board::color_of_city(card)==color){
                                Player::cards.erase(card);
                                count++;
                            }    
                        }    
                    }
                }   
            if(flag){
              Board::update_madication(color);  
            } 
            }
            }   
        return *this;
    } 
    Player& Player::treat(City city){
        Color color=Board::color_of_city(city);
        if(Player::city==city){
            if(Player::board[city]==0){ //if there is no diseas in the city
                throw "Execption-> there is no diseas in the city";
            }
            else if(Board::if_found_madication(color)){ //if there is a medication for this color of city
                Player::board[city]=0;
            }
            else{
                Player::board[city]=Player::board[city]-1;
            }
        }    
        return *this;
    }
    Player& Player::take_card(City city){
        if(!Player::cards.count(city)){ //if the player dont have the card of this city
            Player::cards.insert(city);
        }    
        return *this;
    }
    // string Player::role(){ 
    //     return "";
    // }
    string Player::role(){
        return Player::special_role;
    }
    void Player::remove_cards(){
        Player::cards.clear();
    }
    ostream& operator<<(ostream& out, Player const &player){
        return out;
    }
}