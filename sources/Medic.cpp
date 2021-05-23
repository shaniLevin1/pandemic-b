#include"Medic.hpp"

using namespace pandemic;

Player& Medic::treat(City City){
    if(Player::city==City){
        if(Player::board[City]==0){ //if there is no diseas in the city
            throw "Execption-> there is no diseas in the city";
        }
        if(Player::board[City]>0){
            Player::board[City]=0;
        }
    }   
    else{
        throw "Execption-> different cities";
        } 
    return *this;
    }