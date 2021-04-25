#include <iostream>
#include <vector>
#include <string>
#include "Figure.hpp"
using namespace std;


const vector<vector<string>> positions = {{"a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1"},
                                    {"a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2"},
                                    {"a3", "b3", "c3", "d3", "e3", "f3", "g3", "h3"},
                                    {"a4", "b4", "c4", "d4", "e4", "f4", "g4", "h4"},
                                    {"a5", "b5", "c5", "d5", "e5", "f5", "g5", "h5"},
                                    {"a6", "b6", "c6", "d6", "e6", "f6", "g6", "h6"},
                                    {"a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7"},
                                    {"a8", "b8", "c8", "d8", "e8", "f8", "g8", "h8"}};

void print_len(const int& n, const vector<Figure>& arr){
    vector<Figure> line;

    for (const auto & figure : arr){
        if ((figure.x == n) && (!figure.death))
            line.push_back(figure);
    }

    cout << n + 1 << " ";

    for (size_t i = 0; i < 8; ++i){
        bool flag = false;
        for (const auto & figure : line){
            if (figure.y == i){
                flag = true;
                cout << "║ " + figure.name_figure + " ";
            }
        }
        if (!flag)
            cout << "║   ";
    }
    cout << "║" << endl;
}

void print_sep_table(){
    cout << "  ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣" << endl;
}

void print_top_table(){
    cout << "  ╔═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╗" << endl;
}

void print_low_table(){
    cout << "  ╚═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╝" << endl;
}

void print_table(const vector<Figure>& arr){
    print_top_table();
    for (size_t i = 7; i > 0; --i){
        print_len(i, arr);
        print_sep_table();
    }
    print_len(0, arr);
    print_low_table();
    cout << "    a   b   c   d   e   f   g   h  " << endl;
}

void step_figure(const string& start, const string& end, vector<Figure>& figures){
    unsigned x, y, x_end, y_end;
    for (size_t i = 0; i < 8; ++i){
        for (size_t j = 0; j < 8; ++j){
            if (start == positions[i][j]){
                x = i;
                y = j;
            }
        }
    }

    for (size_t i = 0; i < 8; ++i){
        for (size_t j = 0; j < 8; ++j){
            if (end == positions[i][j]){
                x_end = i;
                y_end = j;
            }
        }
    }

    for (auto & figure : figures){
        if ((figure.x == x_end) && (figure.y == y_end)) {
            figure.death = true;
        }
    }

    for (auto & figure : figures){
        if ((figure.x == x) && (figure.y == y)) {
            figure.x = x_end;
            figure.y = y_end;
        }
    }
}

int main() {
    cout << "     /\\ \\                              \n"
            "  ___\\ \\ \\___      __    ____    ____  \n"
            " /'___\\ \\  _ `\\  /'__`\\ /',__\\  /',__\\ \n"
            "/\\ \\__/\\ \\ \\ \\ \\/\\  __//\\__, `\\/\\__, `\\\n"
            "\\ \\____\\\\ \\_\\ \\_\\ \\____\\/\\____/\\/\\____/\n"
            " \\/____/ \\/_/\\/_/\\/____/\\/___/  \\/___/ " << endl; //Вывод заголовка
    bool starter;
    cout << "Начать новую игру?[1/0]: ";
    cin >> starter;
    if (starter == 0) {
        cout << "GAME OVER!";
        return 0;
    }

    vector<string> history;

    ////Заполняем доску фигурами
    vector<Figure> arr;
    for (size_t i = 0; i < 8; ++i) {
        Figure elem(1, i, "♟");
        arr.push_back(elem);
    }
    for (size_t i = 0; i < 8; ++i) {
        Figure elem(6, i);
        arr.push_back(elem);
    }
    vector<string> name_of_figure_b = {"♜", "♞", "♝", "♛", "♚", "♝", "♞", "♜"};
    vector<string> name_of_figure_w = {"♖", "♘", "♗", "♕", "♔", "♗", "♘", "♖"};
    for (size_t i = 0; i < 8; ++i){
        Figure elem1(7, i, name_of_figure_w[i]);
        Figure elem2(0, i, name_of_figure_b[i]);
        arr.push_back(elem1);
        arr.push_back(elem2);
    }


    print_table(arr);
    int counter_of_steps = 0; //Счетчик ходов

    while (true){
        string command;
        if (counter_of_steps % 2 == 0) {
            cout << "Ход белых:" << endl;
        } else{
            cout << "Ход черных:" << endl;
        }
        cin >> command;
        history.push_back(command);
        if (command == "stop"){
            for (const string& elem : history){
                cout << elem << endl;
            }
            break;
        }
        else {
            counter_of_steps += 1;
        }
        if (command == "0-0"){
            cout << "0-0" << endl << endl;
            if (counter_of_steps % 2 == 1) {
                /*
                int x_1, y_1, x_2, y_2;
                bool flag = true;
                for (size_t i = 0; i < 8; ++i){
                    for (size_t j = 0; j < 8; ++j){
                        if ("e1" == positions[i][j]){
                            x_1 = i;
                            y_1 = j;
                        }
                        if ("h1" == positions[i][j]){
                            x_2 = i;
                            y_2 = j;
                        }
                    }
                }
                for (size_t i = x_1 + 1; i < x_2; ++i){
                    for (auto & figure : arr){
                        if ((figure.x == i) && (figure.y == y_2)) {
                                flag = false;
                        }
                    }
                }*/
                step_figure("e1", "g1", arr);
                step_figure("h1", "f1", arr);
            } else{
                step_figure("e8", "g8", arr);
                step_figure("h8", "f8", arr);
            }
        } else if (command == "0-0-0"){
            cout << "0-0-0" << endl << endl;
            if (counter_of_steps % 2 == 1) {
                step_figure("e1", "c1", arr);
                step_figure("a1", "d1", arr);
            } else{
                step_figure("e8", "c8", arr);
                step_figure("a8", "d8", arr);
            }
        } else {
            cout << endl << endl << endl;
            string start_pos = command.substr(0, 2);
            cout << "Стартовая позиция фигуры: " << start_pos << endl;
            string end_pos = command.substr(2, 2);
            cout << "Конечная позиция фигуры: " << end_pos << endl;

            step_figure(start_pos, end_pos, arr);
        }

        print_table(arr);
    }
    return 0;
}
