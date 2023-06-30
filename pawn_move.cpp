#include "table.h"

vector<pair<int, int>> white_pawn_moves{{0, -1}, { 0,-2 }, { -1,-1 }, { 1,-1 }};
vector<pair<int, int>> black_pawn_moves{{0, 1}, { 0,2 }, { -1,1 }, { 1,1 }};

bool Table::pawn_move(pos pos_i, pos pos_f)
{
    if (table[pos_i.lin][pos_i.col] == 1) {

        ///white pawn
        if (!valid_move(pos_i, pos_f, white_pawn_moves)) return false;

        if (pos_f.lin == 8) {
            int piece;
            cout << "Cititi valoarea piesei in care doriti sa transformati pionul\n";
            cin >> piece;
            table[pos_i.lin][pos_i.col] = piece;
        }

        if (pos_i.col == pos_f.col) {
            if (table[pos_f.lin][pos_f.col] != 0) {
                cout << "Invalid white pawn move\n";
                return false;
            }

            if (pos_f.lin - pos_i.lin == 2)
                if (table[pos_i.lin+1][pos_i.col] != 0 || pos_i.lin!=7) {
                    cout << "Invalid pawn move\n";
                    return false;
                }
        }
        else {
            if (table[pos_f.lin][pos_f.col] >= 0) {
                cout << "Invalid move\n";
                return false;
            }
        }


    }
    else {

        ///black pawn

        if (!valid_move(pos_i, pos_f, black_pawn_moves)) return false;

        if (pos_f.lin == 1) {
            int piece;
            cout << "Cititi valoarea piesei in care doriti sa transformati pionul\n";
            cin >> piece;
            table[pos_i.lin][pos_i.col] = piece;
        }

        if (pos_i.col == pos_f.col) {
            if (table[pos_f.lin][pos_f.col] != 0) {
                cout << "Invalid black pawn move\n";
                return false;
            }

            if (pos_f.lin - pos_i.lin == 2)
                if (table[pos_i.lin + 1][pos_i.col] != 0 || pos_i.lin != 2) {
                    cout << "Invalid pawn move\n";
                    return false;
                }
        }
        else {
            if (table[pos_f.lin][pos_f.col] <= 0) {
                cout << "Invalid move\n";
                return false;
            }
        }
    }
   
    move_piece(pos_i, pos_f);   

    return true;
};