#include"Player.hpp"
#include"Board.hpp"
#include"City.hpp"
#include<iterator>
#include<map>
#include <iostream>
#include <stdexcept>
const auto five = 5;
using namespace std;
namespace pandemic{
    
    Player& Player::drive(City city){ 
        if(Player::city==city){
            throw"exception-> same city";
        }
        if(Board::city_connected(Player::city,city)){
            Player::city=city;
        }
        else{
            throw "exception-> there is no connection between the cities";
        }
        if(special_role=="Medic"){ // added 
            if(board.find_madication(Board::color_of_city(city)))
            {
                board[city]=0;
            }
        }
        return *this;
    }
    Player& Player::fly_direct(City city){
        if(Player::city==city){
            throw"exception->same city";
        }
        if(Player::cards.count(city)!=0){ //the player has the card of the city 
            Player::city=city;
            cards.erase(city);
        }
        else{
            throw"exception-> dont have the card of the city";
        }
        if(special_role=="Medic"){
            if(board.find_madication(Board::color_of_city(city)))
            {
                board[city]=0;
            }
        }
        return *this;
    }
    Player& Player::fly_charter(City c){
        if(cards.count(Player::city)!=0){
            if(Player::city==c){
                throw "exception-> same city";
            }
            if(Player::city!=c){
                cards.erase(c);
                Player::city=c;
                if(special_role=="Medic"){
                    if(board.find_madication(Board::color_of_city(c))){
                        board[c]=0;
                    }
                }
            }
            return *this;

        }
        if(cards.count(Player::city)==0){
            throw "exception-> dont have cards";
        }
        return *this;
    }
    Player& Player::fly_shuttle(City city){ //need to check if we need to drop card from the set
        if(Player::city==city){
            throw"exception-> same city";
        }
        if(Player::board.city_research_stations(city)&&Player::board.city_research_stations(Player::city)){
            Player::city=city;
            if(special_role=="Medic"){
                if(board.find_madication(Board::color_of_city(city))){
                    board[city]=0;
                }
            }
            return *this;
        }
        if(!Player::board.city_research_stations(city)||!Player::board.city_research_stations(Player::city)){
            throw"exception-> one of the cities dont have research station ";
        }
        return *this;
    }
    Player& Player::build(){
        if(cards.count(city)==0){
            throw"exception-> dont have card";
        }
        board.update_research_station(city);
        cards.erase(city);
        return *this;
    }
    Player& Player::discover_cure(Color color){
        if(!board.city_research_stations(Player::city)){
            throw"exception-> dont have research station";
        }
        if(board.city_research_stations(Player::city)){
            if(!board.find_madication(color)){ //if the madication for this color did not found yet
                int count=0; 
                bool flag=false;
                for (const auto &card : Player::cards){
                    if(Board::color_of_city(card)==color){
                        count++;
                    }
                }
            if(count<five){
                throw"exception->dont have 5 cards";
            }    
            if(count>=five){
                    flag=true;
                    count=0;
                    set<City>temp;
                for (const auto &card : Player::cards){
                     if(count<five){
                         if(Board::color_of_city(card)==color){
                            temp.insert(card);
                             count++;
                         }    
                     }    
                 }
                 for (const auto &card : temp){
                    Player::cards.erase(card);
                 }
             } 
          
               
            if(flag){
              board.update_madication(color);  
            }
            }          
        }
        return *this;
    } 
    Player& Player::treat(City city){
        if(city!=Player::city){
            throw "exception-> not the same cities";
        }
        Color color=Board::color_of_city(city);
        if(Player::city==city){
            if(Player::board[city]==0){ //if there is no diseas in the city
                throw "exception-> there is no diseas in the city";
            }
            if(board.find_madication(color)){ //if there is a medication for this color of city
                Player::board[city]=0;
            }
            else{
                Player::board[city]-=1;
            }
        }    
        return *this;
    }
    Player& Player::take_card(City city){
        if(Player::cards.count(city)==0){ //if the player dont have the card of this city
            Player::cards.insert(city);
        }    
        return *this;
    }
    
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