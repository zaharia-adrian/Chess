#pragma once
#include<iostream>
#include <vector>
#include "piece.h"
using std::pair;
using std::cout;
using std::vector;
using std::min;
using std::max;

class Table {

    int table[9][9];
    vector<Piece*> white_pieces;
    vector<Piece*> black_pieces;

    bool valid_table(int);

    bool simulate_attack_table(pair<int,int>,int);
    pair<int, int> get_coordinates(pair<char, int>);
    bool valid_move(pair<int, int>, pair<int, int>, vector<pair<int, int>>);
    bool free_way(pair<int, int>, pair<int, int>);
    void move_piece(pair<int, int>, pair<int, int>);
    void unmake_move(pair<int, int>, pair<int, int>);

    bool king_move(pair<int, int>, pair<int, int>);
    bool queen_move(pair<int, int>, pair<int, int>);
    bool rock_move(pair<int, int>, pair<int, int>);
    bool knight_move(pair<int, int>, pair<int, int>);
    bool bishop_move(pair<int, int>, pair<int, int>);
    bool pawn_move(pair<int, int>, pair<int, int>);



    bool on_table(pair<int, int> position) {
        return (position.first >= 1 && position.first <= 8 && position.second >= 1 && position.second <= 8);
    }
public:
    Table();
    void show_table();
    void make_move(pair<char, int>, pair<char, int>, int);

    void show_vector() {
        for (Piece* p : white_pieces) {
            cout << p->get_position().first << " " << p->get_position().second << "\n";
        }
    }
};
