#pragma once
#include <iostream>
#include <vector>
#include "../piece/piece.h"


using namespace std;

const int king = 6;
const int queen = 5;
const int rook = 4;
const int knight = 3;
const int bishop = 2;
const int pawn = 1;

extern bool king_w_moved;
extern bool rook_a_w_moved;
extern bool rook_h_w_moved;

extern bool king_b_moved;
extern bool rook_a_b_moved;
extern bool rook_h_b_moved;



class Table {
	int table[9][9];

	bool valid_table(int);
	bool is_check(pos, int);
	pos get_coordinates(pair<char, int>);
	bool valid_move(pos, pos, vector<pair<int, int>>);
	bool free_way(pos, pos);
	void move_piece(pos, pos);

	bool king_move(pos, pos);
	bool queen_move(pos, pos);
	bool rook_move(pos, pos);
	bool knight_move(pos, pos);
	bool bishop_move(pos, pos);
	bool pawn_move(pos, pos);
	
	bool on_table(pos position) {
	     return (position.lin >= 1 && position.lin <= 8 && position.col >= 1 && position.col <= 8);
	}

	public:
		vector<Piece*> white_pieces;
	    vector<Piece*> black_pieces;
	    Table();
	    void show_table();
	    bool make_move(pair<char, int>, pair<char, int>, int);
		int get_value(int lin, int col) {
			return table[lin][col];
		}
		void set_value(int lin, int col, int value) {
			table[lin][col] = value;
		}
	
	    /*void show_vector() {
	        for (Piece *p : white_pieces) {
	            cout << p->get_position().lin << " " << p->get_position().col << "\n";
	        }
	    }*/
};
