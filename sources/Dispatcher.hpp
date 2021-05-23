#pragma once
#include "Player.hpp"
#include "Board.hpp"
using namespace std;
using namespace pandemic;
class Dispatcher:public Player{
    public:
        Player& fly_direct(City city) override;
        inline Dispatcher(Board& board, City city):Player(board,city,"Dispatcher"){}
};