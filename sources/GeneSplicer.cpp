#include "GeneSplicer.hpp"
const auto five = 5;
using namespace std;
using namespace pandemic;

Player& GeneSplicer::discover_cure(Color color){
    if(!board.city_research_stations(Player::city)){
        throw"exeption-> there is no research station";
    }
    if(board.city_research_stations(Player::city)){
        if(!board.find_madication(color)){ //if the madication for this color did not found yet
            int count=0; 
            for (const auto& card : Player::cards){
                if(cards.count(card)!=0){
                count++;
                }
            }
            if(count<five){
                throw"exeption->dont have 5 cards";
            }
            if(count>=five){
                board.update_madication(color); 
                count=0;
            set<City>temp;
            for (const auto &card : Player::cards){
                if(count<five){
                    temp.insert(card);
                        count++;    
                }    
            }
            for (const auto &card : temp){
                Player::cards.erase(card);
            }
        } 
                    
    }
        }   
        
    return *this;
    } 