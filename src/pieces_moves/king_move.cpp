#include "../table/table.h"

vector<pair<int, int>> king_moves{{-1, -1}, { 0,-1 }, { 1,-1 }, { -1,0 }, { 1,0 }, { -1,1 }, { 0,1 }, { 1,1 }, { 2,0 }, { -2,0 }};

bool king_w_moved;
bool rook_a_w_moved;
bool rook_h_w_moved;

bool king_b_moved;
bool rook_a_b_moved;
bool rook_h_b_moved;


bool Table::king_move(pos pos_i, pos pos_f)
{
	if (!valid_move(pos_i, pos_f, king_moves)) return false;

	(table[pos_i.lin][pos_i.col] == king) ? white_pieces[0]->set_position(pos_f) : black_pieces[0]->set_position(pos_f);

	if (abs(pos_i.col - pos_f.col) == 2) {

		if (table[pos_i.lin][pos_i.col] == king) {
			if (!king_w_moved) {
				pos rook_w_pos;
				rook_w_pos.lin = 8, rook_w_pos.col = 1;
				if (pos_i.col - pos_f.col == 2 && !rook_a_w_moved && free_way(pos_i, rook_w_pos)) {
					///have to verify check on the first square and current square of the king!!!
					pos rook_w_new_pos;
					rook_w_new_pos.lin = 8, rook_w_new_pos.col = 4;
					move_piece(rook_w_pos, rook_w_new_pos);
					move_piece(pos_i, pos_f);
				}
				rook_w_pos.lin = 8, rook_w_pos.col = 8;
				if (pos_i.col - pos_f.col == -2 && !rook_h_w_moved && free_way(pos_i, rook_w_pos)) {
					///have to verify check on the first square and current square of the king!!!
					pos rook_w_new_pos;
					rook_w_new_pos.lin = 8, rook_w_new_pos.col = 6;
					move_piece(rook_w_pos, rook_w_new_pos);
					move_piece(pos_i, pos_f);
				}
			}
		}
		else {
			if (!king_b_moved) {
				pos rook_b_pos;
				rook_b_pos.lin = 1, rook_b_pos.col = 1;
				cout << "Got here!";
				if (pos_i.col - pos_f.col == 2 && !rook_a_w_moved && free_way(pos_i, rook_b_pos)) {
					///have to verify check on the first square and current square of the king!!!
					pos rook_b_new_pos;
					rook_b_new_pos.lin = 1, rook_b_new_pos.col = 4;
					move_piece(rook_b_pos, rook_b_new_pos);
					move_piece(pos_i, pos_f);
				}
				rook_b_pos.lin = 1, rook_b_pos.col = 8;
				if (pos_i.col - pos_f.col == -2 && !rook_h_w_moved && free_way(pos_i, rook_b_pos)) {
					///have to verify check on the first square and current square of the king!!!
					pos rook_b_new_pos;
					rook_b_new_pos.lin = 1, rook_b_new_pos.col = 6;
					move_piece(rook_b_pos, rook_b_new_pos);
					move_piece(pos_i, pos_f);
				}
			}
		}
	}
	else {
		move_piece(pos_i, pos_f);
	}
	return true;
}