#include "table.h"

bool Table::valid_table(int color) {
	if (color == 1) {
		///white moved, white should not be in check
		pos white_king_pos = (*white_pieces[0]).get_position();
		//cout << white_king_pos.lin << " " << white_king_pos.col << "\n";
		return is_check(white_king_pos, 1);
	}
	else {
		///black moved, black should not be in check
		pos black_king_pos = (*black_pieces[0]).get_position();
		//cout << black_king_pos.lin << " " << b_king_pos.col << "\n";
		return is_check(black_king_pos, -1);
	}
}

bool Table::is_check(pos king_pos, int color) {
	for (int col = king_pos.col + 1, lin = king_pos.lin + 1; col <= 8 && lin <= 8; col++, lin++) {
		if (table[lin][col] == -color * queen || table[lin][col] == -color * bishop) {
			cout << "Queen or bishop check\n";
			return false;
		}
		if (table[lin][col] != 0) break;
	}

	for (int col = king_pos.col + 1, lin = king_pos.lin - 1; col <= 8 && lin >= 1; col++, lin--) {
		if (table[lin][col] == -color * queen || table[lin][col] == -color * bishop) {
			cout << "Queen or bishop check\n";
			return false;
		}
		if (table[lin][col] != 0) break;
	}

	for (int col = king_pos.col - 1, lin = king_pos.lin + 1; col >= 1 && lin <= 8; col--, lin++) {
		if (table[lin][col] == -color * queen || table[lin][col] == -color * bishop) {
			cout << "Queen or bishop check\n";
			return false;
		}
		if (table[lin][col] != 0) break;

	}
	for (int col = king_pos.col - 1, lin = king_pos.lin - 1; col >= 1 && lin >= 1; col--, lin--) {
		if (table[lin][col] == -color * queen || table[lin][col] == -color * bishop) {
			cout << "Queen or bishop check\n";
			return false;
		}
		if (table[lin][col] != 0) break;
	}
	for (int col = king_pos.col - 1; col >= 1; col--) {
		if (table[king_pos.lin][col] == -color * queen || table[king_pos.lin][col] == -color * rook) { cout << "Queen or rock check\n"; return false; }
		if (table[king_pos.lin][col] != 0) break;
	}
	for (int col = king_pos.col + 1; col <= 8; col++) {
		if (table[king_pos.lin][col] == -color * queen || table[king_pos.lin][col] == -color * rook) { cout << "Queen or rock check\n"; return false; }
		if (table[king_pos.lin][col] != 0) break;
	}

	for (int lin = king_pos.lin - 1; lin >= 1; lin--) {
		if (table[lin][king_pos.col] == -color * queen || table[lin][king_pos.col] == -color * rook) { cout << "Queen or rock check\n"; return false; }
		if (table[lin][king_pos.col] != 0) break;
	}

	for (int lin = king_pos.lin + 1; lin <= 8; lin++) {
		if (table[lin][king_pos.col] == -color * queen || table[lin][king_pos.col] == -color * rook) { cout << "Queen or rock check\n"; return false; }
		if (table[lin][king_pos.col] != 0) break;
	}

	int d_lin[] = { -1,-2,-2,-1,1,2,2,1 };
	int d_col[] = { -2,-1,1,2,2,1,-1,-2 };

	for (int k = 0; k < 8; k++) {
		int lin = king_pos.lin + d_lin[k];
		int col = king_pos.col + d_col[k];
		if (on_table({ lin,col }))
			if (table[lin][col] == knight * (-color)) {
				cout << "Knight check"; return false;
			}
	}
	return true;
}