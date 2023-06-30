#include "table.h"

bool Table::valid_move(pos pos_i, pos pos_f, vector<pair<int, int>> moves)
{
	for (pair<int, int> m : moves)
		if (pos_i.lin + m.second == pos_f.lin && pos_i.col + m.first == pos_f.col)
			return true;
	cout << "Invalid move (not on the list of moves of this piece)\n";
	return false;
}

bool Table::free_way(pos pos_i, pos pos_f)
{
	cout << "Verify free way from {" << pos_i.lin << ", " << pos_i.col << "} and {" << pos_f.lin << ", " << pos_f.col << "}\n";
	if (pos_i.lin == pos_f.lin) {
		for (int i = min(pos_i.col, pos_f.col) + 1; i <= max(pos_i.col, pos_f.col) - 1; i++)
			if (table[pos_i.lin][i]) return false;
	}
	else if (pos_i.col == pos_f.col) {
		for (int i = min(pos_i.lin, pos_f.lin) + 1; i <= max(pos_i.lin, pos_f.lin) - 1; i++)
			if (table[i][pos_i.col]) return false;
	}
	else {
		if (pos_i.lin > pos_f.lin) {
			if (pos_i.col > pos_f.col) {
				for (int lin = pos_f.lin + 1, col = pos_f.col + 1; lin < pos_i.lin; lin++, col++) if (table[lin][col]) return false;
			}
			else {
				for (int lin = pos_f.lin + 1, col = pos_f.col - 1; lin < pos_i.lin; lin++, col--) if (table[lin][col]) return false;
			}
		}
		else {
			if (pos_i.col > pos_f.col) {
				for (int lin = pos_f.lin - 1, col = pos_f.col + 1; lin > pos_i.lin; lin--, col++) if (table[lin][col]) return false;
			}
			else {
				for (int lin = pos_f.lin - 1, col = pos_f.col - 1; lin > pos_i.lin; lin--, col--) if (table[lin][col]) return false;
			}
			
		}
	}

	return true;
}



void Table::move_piece(pos pos_i, pos pos_f) {
	table[pos_f.lin][pos_f.col] = table[pos_i.lin][pos_i.col];
	table[pos_i.lin][pos_i.col] = 0;
}



bool Table::make_move(pair<char, int> i, pair<char, int> f, int color)
{

	pos pos_i = get_coordinates(i);
	pos pos_f = get_coordinates(f);

	bool valid = true;

	int copy_table[9][9];
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++) copy_table[i][j] = table[i][j];

	if (!on_table(pos_i) || !on_table(pos_f)) {
		cout << "Positions are not on the table or invalid\n";
		return false;
	}
	if (table[pos_i.lin][pos_i.col] * table[pos_f.lin][pos_f.col] > 0) {
		return false;
	}


	switch (table[pos_i.lin][pos_i.col] * color)
	{
	case king:
		valid = king_move(pos_i, pos_f);
		break;
	case queen:
		valid = queen_move(pos_i, pos_f);
		break;
	case rook:
		valid = rook_move(pos_i, pos_f);
		break;
	case knight:
		valid = knight_move(pos_i, pos_f);
		break;
	case bishop:
		valid = bishop_move(pos_i, pos_f);
		break;
	case pawn:
		valid = pawn_move(pos_i, pos_f);
		break;
	default:
		valid = false;
		break;
	}

	if (!valid) return false;

	if (!valid_table(color)) {
		cout << "Invalid table \n";
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++) table[i][j] = copy_table[i][j];

		if (abs(table[pos_f.lin][pos_f.col]) == king)
			(table[pos_f.lin][pos_f.col] == king) ? white_pieces[0]->set_position(pos_i) : black_pieces[0]->set_position(pos_i);
		return false;
	}


	if (table[pos_f.lin][pos_f.col] == rook) {
		if (pos_i.col == 1) rook_a_w_moved = true;
		if (pos_i.col == 8) rook_h_w_moved = true;
	}
	if (table[pos_f.lin][pos_f.col] == -rook) {
		if (pos_i.col == 1) rook_a_b_moved = true;
		if (pos_i.col == 8) rook_h_b_moved = true;
	}
	if (table[pos_f.lin][pos_f.col] == king) king_w_moved = true;
	if (table[pos_f.lin][pos_f.col] == -king) king_b_moved = true;
	return true;
}