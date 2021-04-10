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
    int starter;
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
        print_table(arr);
    }
    return 0;
}