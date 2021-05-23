#pragma once
#include "Player.hpp"
#include "Board.hpp"
using namespace std;
using namespace pandemic;
class Scientist:public Player{
    public:
        Player& discover_cure(Color color) override;
        inline Scientist(Board& board, City city, int num):Player(board,city,"Scientist",num){}
};