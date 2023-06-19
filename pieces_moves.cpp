#include "table.h"
using std::vector;


vector<pair<int, int>> king_moves{{-1, -1}, { 0,1 }, { 1,-1 }, { -1,0 }, { 1,0 }, { -1,1 }, { 0,1 }, { 1,1 }};
vector<pair<int, int>> queen_moves{{1, 1}, { -1,1 }, { -1,-1 }, { 1,-1 }, { 0,1 }, { 0,-1 }, { 1,0 }, { -1,0 }, { 2,2 }, { -2,2 }, { -2,-2 }, { 2,-2 }, { 0,2 }, { 0,-2 }, { 2,0 }, { -2,0 }, { 3,3 }, { -3,3 }, { -3,-3 }, { 3,-3 }, { 0,3 }, { 0,-3 }, { 3,0 }, { -3,0 }, { 4,4 }, { -4,4 }, { -4,-4 }, { 4,-4 }, { 0,4 }, { 0,-4 }, { 4,0 }, { -4,0 }, { 5,5 }, { -5,5 }, { -5,-5 }, { 5,-5 }, { 0,5 }, { 0,-5 }, { 5,0 }, { -5,0 }, { 6,6 }, { -6,6 }, { -6,-6 }, { 6,-6 }, { 0,6 }, { 0,-6 }, { 6,0 }, { -6,0 }, { 7,7 }, { -7,7 }, { -7,-7 }, { 7,-7 }, { 0,7 }, { 0,-7 }, { 7,0 }, { -7,0 }, { 8,8 }, { -8,8 }, { -8,-8 }, { 8,-8 }, { 0,8 }, { 0,-8 }, { 8,0 }, { -8,0 }};
vector<pair<int, int>> rock_moves{{0, 1}, { 0,-1 }, { 1,0 }, { -1,0 }, { 0,2 }, { 0,-2 }, { 2,0 }, { -2,0 }, { 0,3 }, { 0,-3 }, { 3,0 }, { -3,0 }, { 0,4 }, { 0,-4 }, { 4,0 }, { -4,0 }, { 0,5 }, { 0,-5 }, { 5,0 }, { -5,0 }, { 0,6 }, { 0,-6 }, { 6,0 }, { -6,0 }, { 0,7 }, { 0,-7 }, { 7,0 }, { -7,0 }, { 0,8 }, { 0,-8 }, { 8,0 }, { -8,0 }};
vector<pair<int, int>> knight_moves{{-2, -1}, { -2,1 }, { -1,-2 }, { 1,-2 }, { 2,-1 }, { 2,1 }, { 1,2 }, { -1,2 }};
vector<pair<int, int>> bishop_moves{{1, 1}, { -1,1 }, { -1,-1 }, { 1,-1 }, { 2,2 }, { -2,2 }, { -2,-2 }, { 2,-2 }, { 3,3 }, { -3,3 }, { -3,-3 }, { 3,-3 }, { 4,4 }, { -4,4 }, { -4,-4 }, { 4,-4 }, { 5,5 }, { -5,5 }, { -5,-5 }, { 5,-5 }, { 6,6 }, { -6,6 }, { -6,-6 }, { 6,-6 }, { 7,7 }, { -7,7 }, { -7,-7 }, { 7,-7 }, { 8,8 }, { -8,8 }, { -8,-8 }, { 8,-8 }};
vector<pair<int, int>> white_pawn_moves{{0, -1}, { 0,-2 }, { -1,-1 }, { 1,-1 }};
vector<pair<int, int>> black_pawn_moves{{0, 1}, { 0,2 }, { -1,1 }, { 1,1 }};

bool Table::valid_move(pair<int, int> pos_i, pair<int, int> pos_f, vector<pair<int, int>> moves)
{   
    for (pair<int, int> m : moves)
        if (pos_i.first + m.first == pos_f.first && pos_i.second + m.second == pos_f.second)
        {
            return true;
        }
    cout << "Invalid move/n";
    return false;
}
bool Table::free_way(pair<int, int> pos_i, pair<int, int> pos_f)
{
    if (pos_i.first == pos_f.first) {
        for (int i = min(pos_i.first, pos_f.first) + 1; i <= max(pos_i.first, pos_f.first) - 1; i++)
            if (table[i][pos_i.first]) return false;
    }
    else if (pos_i.second == pos_f.second) {
        for (int i = min(pos_i.second, pos_f.second) + 1; i <= max(pos_i.second, pos_f.second) - 1; i++)
            if (table[pos_i.first][i]) return false;
    }
    else
        for (int i = min(pos_i.second, pos_f.second) + 1, j = min(pos_i.first, pos_f.first) + 1; i <= max(pos_i.second, pos_f.second) - 1; i++, j++)
            if (table[j][i]) return false;

    return true;
}

bool Table::king_move(pair<int, int> pos_i, pair<int, int> pos_f)
{
    if (!valid_move(pos_i, pos_f, king_moves)) return false;
}

bool Table::queen_move(pair<int, int> pos_i, pair<int, int> pos_f)
{
    bool valid = valid_move(pos_i, pos_f, queen_moves);
    return valid;
};

bool Table::rock_move(pair<int, int> pos_i, pair<int, int> pos_f)
{
    bool valid = valid_move(pos_i, pos_f, rock_moves);
    return valid;
};

bool Table::knight_move(pair<int, int> pos_i, pair<int, int> pos_f)
{
    if (!valid_move(pos_i, pos_f, knight_moves)) {
         cout << "Invalid knight move\n";
         return false;
    }
    cout << "Valid knight move\n";
    move_piece(pos_i, pos_f);
    return true;
};

bool Table::bishop_move(pair<int, int> pos_i, pair<int, int> pos_f)
{
    bool valid = valid_move(pos_i, pos_f, bishop_moves);
    return valid;
};

bool Table::pawn_move(pair<int, int> pos_i, pair<int, int> pos_f)
{
    if (table[pos_i.second][pos_i.first] == 1) {
        if (!valid_move(pos_i, pos_f, white_pawn_moves)) {
            cout << "Invalid white pawn move\n";
            return false;
        }
    }
    else{
        if (!valid_move(pos_i, pos_f, black_pawn_moves)) {
            cout << "Invalid black pawn move\n";
            return false;
        }
    }
    if (pos_i.first == pos_f.first) {
        if (table[pos_f.second][pos_f.first] != 0) {
            cout << "Invalid pawn move\n";
            return false;
        }
        if(abs(pos_i.second-pos_f.second)==2)
            if (table[min(pos_i.second, pos_f.second) + 1][pos_i.first] != 0) {
                cout << "Invalid pawn move\n";
            }
    }
    move_piece(pos_i,pos_f);

    return true;
};

void Table::move_piece(pair<int, int> pos_i, pair<int, int> pos_f) {
    table[pos_f.second][pos_f.first] = table[pos_i.second][pos_i.first];
    table[pos_i.second][pos_i.first] = 0;
}

void Table::unmake_move(pair<int, int> pos_i, pair<int, int> pos_f) {
    table[pos_i.second][pos_i.first] = table[pos_f.second][pos_f.first];
    table[pos_f.second][pos_f.first] = 0;
}