#pragma once
#include "Player.hpp"
#include "Board.hpp"
using namespace std;
using namespace pandemic;
class Medic:public Player{
    public:
        inline Medic(Board& board, City city):Player(board,city,"Medic"){
            Color color=board.color_of_city(city);
            if(board.color_madication[color]){
                board[city]=0;
            }
        }
        Player& treat(City City) override;
        
};