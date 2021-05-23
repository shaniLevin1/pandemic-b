#pragma once
#include "Player.hpp"
#include "Board.hpp"
using namespace std;
using namespace pandemic;
class GeneSplicer:public Player{
    public:
        inline GeneSplicer(Board& board, City city):Player(board,city,"GeneSplicer"){}
        Player& discover_cure(Color color) override;
};