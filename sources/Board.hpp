#pragma once
#include<string>
#include<map>
#include<set>
#include<list>
#include"City.hpp"
#include"Color.hpp"


namespace pandemic{
    class Board{
        
            static map<City,Color> city_color;
            static map<City,set<City>> city_connection;
            map<City, int> city_diseas_cubes;
            set<City> research_stations;

        public: 
           Board(){}
           int& operator[](City city);
           friend ostream& operator<<(ostream& out,const Board& board);
           bool is_clean(); 
           void remove_cures();
           static bool city_connected(City& city1,City& city2);
           bool city_research_stations(City city);
           void update_research_station(City city);
           static Color color_of_city(City city);
           bool find_madication(Color color);
           void update_madication(Color color);
           bool if_found_madication(Color color);
           void update_color_madication(Color color);
           void remove_stations();
           
           map<Color,bool> color_madication{
            {{Black,false},
            {Blue,false},
            {Yellow,false},
            {Red,false}}
            };
    };
};
    

    


