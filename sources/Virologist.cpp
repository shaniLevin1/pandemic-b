#include"Virologist.hpp"

using namespace pandemic;

Player& Virologist::treat(City City){
    Color color=Board::color_of_city(city);
    if(Player::city!=City){
        if(cards.count(City)==0){
            throw "exception->dont have card";
        }
        cards.erase(City);
    }
    else if(board[City]==0){
        throw "exception->board have 0 cube daseasis";
    }
    else if(board.find_madication(color))
        {
            board[City]=0;
            return *this;
        }
    board[City]--;
    return *this;
    }