#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Figure{
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

vector<vector<string>> positions = {{"a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1"},
                                    {"a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2"},
                                    {"a3", "b3", "c3", "d3", "e3", "f3", "g3", "h3"},
                                    {"a4", "b4", "c4", "d4", "e4", "f4", "g4", "h4"},
                                    {"a5", "b5", "c5", "d5", "e5", "f5", "g5", "h5"},
                                    {"a6", "b6", "c6", "d6", "e6", "f6", "g6", "h6"},
                                    {"a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7"},
                                    {"a8", "b8", "c8", "d8", "e8", "f8", "g8", "h8"}};

void print_len(int n, vector<Figure> arr){
    cout << n + 1 << " ";
    vector<Figure> line;
    for (int i = 0; i < arr.size(); ++i){
        if (arr[i].x != n)
            continue;
        line.push_back(arr[i]);
    }
    for (int i = 0; i < 8; ++i){
        bool flag = false;
        for (int j = 0; j < line.size(); ++j){
            if (line[j].y == i){
                flag = true;
                cout << "║ " + line[j].name_figure + " ";
            }
        }
        if (flag == false)
            cout << "║   ";
    }
    cout << "║" << endl;
}

void print_sep_table(){
    cout << "  ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣" << endl;
}

void print_top_table(){
    cout << "  ╔═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╗\n";
}

void print_low_table(){
    cout << "  ╚═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╝\n";
}

void print_table(vector<Figure> arr){
    print_top_table();
    print_len(7, arr);
    print_sep_table();
    print_len(6, arr);
    print_sep_table();
    print_len(5, arr);
    print_sep_table();
    print_len(4, arr);
    print_sep_table();
    print_len(3, arr);
    print_sep_table();
    print_len(2, arr);
    print_sep_table();
    print_len(1, arr);
    print_sep_table();
    print_len(0, arr);
    print_low_table();
    cout << "    a   b   c   d   e   f   g   h  " << endl;
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

    ////Заполняем доску фигурами
    vector<Figure> arr;
    for (int i = 0; i < 8; ++i) {
        Figure elem(1, i, "♟");
        arr.push_back(elem);
    }
    for (int i = 0; i < 8; ++i) {
        Figure elem(6, i);
        arr.push_back(elem);
    }
    vector<string> name_of_figure_b = {"♜", "♞", "♝", "♛", "♚", "♝", "♞", "♜"};
    vector<string> name_of_figure_w = {"♖", "♘", "♗", "♕", "♔", "♗", "♘", "♖"};
    for (int i = 0; i < 8; ++i){
        Figure elem1(7, i, name_of_figure_w[i]);
        Figure elem2(0, i, name_of_figure_b[i]);
        arr.push_back(elem1);
        arr.push_back(elem2);
    }


    print_table(arr);
    int counter_of_steps = 0; //Счетчик ходов

    while (true){
        string command;
        cout << "Введите команду: " << endl;
        cin >> command;
        if (command == "stop"){
            break;
        }
        cout << endl << endl << endl << endl;
        string start_pos = command.substr(0,2);
        cout << "Стартовая позиция фигуры: " << start_pos << endl;
        string end_pos = command.substr(2,2);
        cout << "Конечная позиция фигуры: " << end_pos << endl;




        int x, y, x_end, y_end;
        for (int i = 0; i < 8; ++i){
            for (int j = 0; j < 8; ++j){
                if (start_pos == positions[i][j]){
                    x = i;
                    y = j;
                }
            }
        }

        for (int i = 0; i < 8; ++i){
            for (int j = 0; j < 8; ++j){
                if (end_pos == positions[i][j]){
                    x_end = i;
                    y_end = j;
                }
            }
        }

        for (int i = 0; i < arr.size(); ++i){
            if ((arr[i].x == x) && (arr[i].y == y)) {
                arr[i].x = x_end;
                arr[i].y = y_end;
            }
        }



        print_table(arr);
    }
    return 0;
}