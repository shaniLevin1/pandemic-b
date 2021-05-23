#include "Dispatcher.hpp"

using namespace std;
using namespace pandemic;

Player& Dispatcher::fly_direct(City city){
    if(Player::city==city){
            throw"Exeption-> same city";
        }
    if(board.city_research_stations(Player::city)){
        Player::city=city;
        if(special_role=="Medic"){
            if(board.find_madication(Board::color_of_city(city))){
                board[city]=0;
            }
        }
    }
    else if(cards.count(city)!=0){
        cards.erase(city);
        Player::city=city;
        if(special_role=="Medic"){
            if(board.find_madication(Board::color_of_city(city))){
                board[city]=0;
            }
        }
    }
    else{
        throw"Execption-> dont have the card of the city";
    }
    return *this;
    }