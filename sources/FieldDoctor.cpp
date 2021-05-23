#include "FieldDoctor.hpp"

using namespace std;
using namespace pandemic;

Player& FieldDoctor::treat(City city){
    Color color=Board::color_of_city(city);
    if(Board::city_connected(Player::city,city)||city==Player::city){
        if(Player::board[city]==0){ //if there is no diseas in the city
            throw "Execption-> there is 0 diseas cubes in the city";
        }
        if(board.find_madication(color)){ //if there is a medication for this color of city
            Player::board[city]=0;
        }
        else{
            Player::board[city]=Player::board[city]-1;
        }
    }
    else{
        throw "Execption-> not the same or connected cities";
    }
  
    return *this;    
    }