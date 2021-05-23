#include"Medic.hpp"

using namespace pandemic;

Player& Medic::treat(City City){
    if(Player::city==City){
        if(Player::board[City]==0){ //if there is no diseas in the city
            throw "exception-> there is no diseas in the city";
        }
        if(Player::board[City]>0){
            Player::board[City]=0;
        }
    }   
    else{
        throw "exception-> different cities";
        } 
    return *this;
    }