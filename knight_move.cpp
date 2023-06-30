#include "table.h"

vector<pair<int, int>> knight_moves{{-2, -1}, { -2,1 }, { -1,-2 }, { 1,-2 }, { 2,-1 }, { 2,1 }, { 1,2 }, { -1,2 }};

bool Table::knight_move(pos pos_i, pos pos_f)
{
    if (!valid_move(pos_i, pos_f, knight_moves)) return false;
   

    if (table[pos_f.lin][pos_f.col] * table[pos_i.lin][pos_i.col] > 0) {
        cout << "Invalid knight move\n";
        return false;
    }

    move_piece(pos_i, pos_f);
    return true;
};
