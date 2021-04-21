//
// Created by Misha Dolbnin on 17.04.2021.
//

#ifndef CHESS_FIGURE_HPP
#define CHESS_FIGURE_HPP
#include <string>
using namespace std;

class Figure {
public:
    Figure(int X, int Y, string name){
        x = X;
        y = Y;
        name_figure = name;
    }
    Figure(int X, int Y){
        x = X;
        y = Y;
    }
    int x = 0;
    int y = 0;
    string name_figure = "♙";
    bool death = false;
};


#endif //CHESS_FIGURE_HPP
