#include"Scientist.hpp"
#include<iostream>
using namespace pandemic;

Player& Scientist::discover_cure(Color color){
     if(!board.city_research_stations(Player::city)){
         throw"exception-> there is no research station";
     }
     if(!board.find_madication(color)){ //if the madication for this color did not found yet
            int count=0; 
            bool flag=false;
            for (const auto& card : cards){
                if(Board::color_of_city(card)==color){
                    count++;
                }
            }
            if(count<n){
                throw"exception->dont have n cards";
            }
            if(count>=n){
                flag=true;
                count=0;   
                set<City>temp;
                for (const auto &card : cards){
                     if(count<n){
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