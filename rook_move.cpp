#include "table.h"

vector<pair<int, int>> rook_moves{{0, 1}, { 0,-1 }, { 1,0 }, { -1,0 }, { 0,2 }, { 0,-2 }, { 2,0 }, { -2,0 }, { 0,3 }, { 0,-3 }, { 3,0 }, { -3,0 }, { 0,4 }, { 0,-4 }, { 4,0 }, { -4,0 }, { 0,5 }, { 0,-5 }, { 5,0 }, { -5,0 }, { 0,6 }, { 0,-6 }, { 6,0 }, { -6,0 }, { 0,7 }, { 0,-7 }, { 7,0 }, { -7,0 }, { 0,8 }, { 0,-8 }, { 8,0 }, { -8,0 }};

bool Table::rook_move(pos pos_i, pos pos_f)
{
    if (!valid_move(pos_i, pos_f, rook_moves)) return false;

    if (!free_way(pos_i, pos_f)) {
        cout << "The way is not free";
        return false;
    }
    move_piece(pos_i, pos_f);
    return true;
};