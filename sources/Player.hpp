#pragma once
#include<string>
#include "Board.hpp"

using namespace std;
namespace pandemic{
class Player{
    protected:
        Board& board;
        City city;
        int n;
        set<City> cards;
        string special_role="";
    public:
        inline Player(Board &b,City c,string special_role):board(b),city(c),special_role(special_role){}
        inline Player(Board &b,City c,string special_role,int num):board(b),city(c),special_role(special_role),n(num){}
        virtual Player& drive(City city);
        virtual Player& fly_direct(City city);
        virtual Player& fly_charter(City c);
        virtual Player& fly_shuttle(City city);
        virtual Player& build();
        virtual Player& discover_cure(Color color);  
        virtual Player& treat(City city);
        Player& take_card(City city);
        virtual string role(); 
        virtual void remove_cards();
        friend ostream& operator<<(ostream& out, Player const &player);
};
}
