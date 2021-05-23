#pragma once
#include "Player.hpp"
#include "Board.hpp"
using namespace std;
using namespace pandemic;
class OperationsExpert: public Player {
    public:
        inline OperationsExpert(Board& board, City city):Player(board,city,"OperationsExpert"){}
        Player& build() override;
};