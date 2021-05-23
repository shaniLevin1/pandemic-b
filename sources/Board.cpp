#include"Board.hpp"
#include <map>
#include <string>
#include<set>
#include<iostream>
using namespace std;
namespace pandemic{

    int& Board::operator[](City city){
        return city_diseas_cubes[city];
    } 
    ostream& operator<<(ostream& out,const Board& board){
        return out;
    }
    bool Board::is_clean(){
        for(const auto& city: city_diseas_cubes) {
            if(city.second>0) {
                return false;
            }
        }
        return true;
    }
    void Board::remove_cures(){
        map<Color, bool>::iterator it;
        for (it = Board::color_madication.begin(); it != Board::color_madication.end(); it++){
           Board::color_madication.at(it->first)=false;
        }
    }
    bool Board::city_connected(City& city1, City& city2) {
        
        return(city_connection.at(city1).count(city2)!=0)&&(city_connection.at(city2).count(city1)!=0); //if count func return 1-contains if 0-not
    }
    
    bool Board::city_research_stations(City city){
        return research_stations.count(city)!=0;
    }

    void Board::update_research_station(City city){
        research_stations.insert(city);
    }

    Color Board::color_of_city(City city){
        return city_color.at(city);
    }

    bool Board::find_madication(Color color){
        return color_madication[color];
    }

    void Board::update_madication(Color color){
        color_madication[color]=true;
    }

    void Board::remove_stations(){
        set<City>::iterator it;
        for(it = research_stations.begin(); it != research_stations.end(); it++){
            research_stations.erase(it);
        }
    }

    map<City,Color> Board::city_color=
                        {{Algiers,Black},
                        { Atlanta, Blue },
                        { Baghdad, Black },
                        { Bangkok, Red },
                        { Beijing, Red },
                        { Bogota, Yellow },
                        { BuenosAires, Yellow },
                        { Cairo, Black },
                        { Chennai, Black },
                        { Chicago, Blue },
                        { Delhi, Black },
                        { Essen, Blue },
                        { HoChiMinhCity, Red },
                        { HongKong, Red },
                        { Istanbul, Black },
                        { Jakarta, Red },
                        { Johannesburg, Yellow },
                        { Karachi, Black },
                        { Khartoum, Yellow },
                        { Kinshasa, Yellow },
                        { Kolkata, Black },
                        { Lagos, Yellow },
                        { Lima, Yellow },
                        { London, Blue },
                        { LosAngeles, Yellow },
                        { Madrid, Blue },
                        { Manila, Red },
                        { MexicoCity, Yellow },
                        { Miami, Yellow },
                        { Milan, Blue },
                        { Montreal, Blue },
                        { Moscow, Black },
                        { Mumbai, Black },
                        { NewYork, Blue },
                        { Osaka, Red },
                        { Paris, Blue },
                        { Riyadh, Black },
                        { SanFrancisco, Blue },
                        { Santiago, Yellow },
                        { SaoPaulo, Yellow },
                        { Seoul, Red },
                        { Shanghai, Red },
                        { StPetersburg, Blue },
                        { Sydney, Red },
                        { Taipei, Red },
                        { Tehran, Black },
                        { Tokyo, Red },
                        { Washington, Blue }
                    };
    map<City,set<City>> Board::city_connection{
             { Algiers, {Madrid, Paris, Istanbul, Cairo } },
            { Atlanta, {Chicago, Miami, Washington } },
            { Baghdad, {Tehran, Istanbul, Cairo, Riyadh, Karachi } },
            { Bangkok, {Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong } },
            { Beijing, {Shanghai, Seoul } },
            { Bogota, {MexicoCity, Lima, Miami, SaoPaulo, BuenosAires } },
            { BuenosAires, {Bogota, SaoPaulo } },
            { Cairo, {Algiers, Istanbul, Baghdad, Khartoum, Riyadh } },
            { Chennai, {Mumbai, Delhi, Kolkata, Bangkok, Jakarta } },
            { Chicago, {SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal } },
            { Delhi, {Tehran, Karachi, Mumbai, Chennai, Kolkata } },
            { Essen, {London, Paris, Milan, StPetersburg } },
            { HoChiMinhCity, {Jakarta, Bangkok, HongKong, Manila } },
            { HongKong, {Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei } },
            { Istanbul, {Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow }},
            { Jakarta, {Chennai, Bangkok, HoChiMinhCity, Sydney } },
            { Johannesburg, {Kinshasa, Khartoum } },
            { Karachi, {Tehran, Baghdad, Riyadh, Mumbai, Delhi } },
            { Khartoum, {Cairo, Lagos, Kinshasa, Johannesburg } },
            { Kinshasa, {Lagos, Khartoum, Johannesburg } },
            { Kolkata, {Delhi, Chennai, Bangkok, HongKong } },
            { Lagos, {SaoPaulo, Khartoum, Kinshasa } },
            { Lima, {MexicoCity, Bogota, Santiago } },
            { London, {NewYork, Madrid, Essen, Paris } },
            { LosAngeles, {SanFrancisco, Chicago, MexicoCity, Sydney } },
            { Madrid, {London, NewYork, Paris, SaoPaulo, Algiers } },
            { Manila, {Taipei, SanFrancisco, HoChiMinhCity, Sydney, HongKong } },
            { MexicoCity, {LosAngeles, Chicago, Miami, Lima, Bogota } },
            { Miami, {Atlanta, MexicoCity, Washington, Bogota } },
            { Milan, {Essen, Paris, Istanbul } },
            { Montreal, {Chicago, Washington, NewYork } },
            { Moscow, {StPetersburg, Istanbul, Tehran } },
            { Mumbai, {Karachi, Delhi, Chennai } },
            { NewYork, {Montreal, Washington, London, Madrid } },
            { Osaka, {Taipei, Tokyo } },
            { Paris, {Algiers, Essen, Madrid, Milan, London } },
            { Riyadh, {Baghdad, Cairo, Karachi } },
            { SanFrancisco, {LosAngeles, Chicago, Tokyo, Manila } },
            { Santiago, {Lima } },
            { SaoPaulo, {Bogota, BuenosAires, Lagos, Madrid } },
            { Seoul, {Beijing, Shanghai, Tokyo } },
            { Shanghai, {Beijing, HongKong, Taipei, Seoul, Tokyo } },
            { StPetersburg, {Essen, Istanbul, Moscow } },
            { Sydney, {Jakarta, Manila, LosAngeles } },
            { Taipei, {Shanghai, HongKong, Osaka, Manila } },
            { Tehran, {Baghdad, Moscow, Karachi, Delhi } },
            { Tokyo, {Seoul, Shanghai, Osaka, SanFrancisco } },
            { Washington, {Atlanta, NewYork, Montreal, Miami } }
        };
    
}