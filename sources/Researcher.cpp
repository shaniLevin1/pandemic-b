#include"Researcher.hpp"
#include<iostream>
const auto five = 5;
using namespace pandemic;

Player& Researcher::discover_cure(Color color){
    if(!board.find_madication(color)){ //if the madication for this color did not found yet
            int count=0; 
            bool flag=false;
            for (const auto& card : Player::cards){
                if(Board::color_of_city(card)==color){
                    count++;
                }
            }
            if(count<five){
                throw"exeption->dont have 5 cards";
            }
            if(count>=five){
                flag=true;
                count=0;
                set<City>temp;
                for (const auto &card : Player::cards){
                     if(count<five){
                         if(Board::color_of_city(card)==color){
                            temp.insert(card);
                             count++;
                         }    
                     }    
                 }
                 for (const auto &card : temp){
                    Player::cards.erase(card);
                 }
             }    
        if(flag){
            board.update_madication(color);  
        } 
        }   
    return *this;
    } 