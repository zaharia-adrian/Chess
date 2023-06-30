#include "table.h"

vector<pair<int, int>> bishop_moves{{1, 1}, { -1,1 }, { -1,-1 }, { 1,-1 }, { 2,2 }, { -2,2 }, { -2,-2 }, { 2,-2 }, { 3,3 }, { -3,3 }, { -3,-3 }, { 3,-3 }, { 4,4 }, { -4,4 }, { -4,-4 }, { 4,-4 }, { 5,5 }, { -5,5 }, { -5,-5 }, { 5,-5 }, { 6,6 }, { -6,6 }, { -6,-6 }, { 6,-6 }, { 7,7 }, { -7,7 }, { -7,-7 }, { 7,-7 }, { 8,8 }, { -8,8 }, { -8,-8 }, { 8,-8 }};

bool Table::bishop_move(pos pos_i, pos pos_f)
{
    if (!valid_move(pos_i, pos_f, bishop_moves)) return false;

    if (!free_way(pos_i, pos_f)) {
        cout << "Invalid the way is not free\n";
        return false;
    }

    move_piece(pos_i, pos_f);
    return true;
};