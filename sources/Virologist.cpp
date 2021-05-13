#include"Virologist.hpp"

using namespace pandemic;

Player& Virologist::treat(City City){
    Color color=Board::color_of_city(city);
    if(Player::board[city]==0){ //if there is no diseas in the city
        throw "Execption-> there is no diseas in the city";
    }
    else if(Board::if_found_madication(color)){ //if there is a medication for this color of city
        Player::board[city]=0;
    }
    else{
        Player::board[city]=Player::board[city]-1;
    }
    return *this;
    }