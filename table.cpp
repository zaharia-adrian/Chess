#include  <iostream>
#include "table.h"

using std::cout;
using std::pair;

const int king = 6;
const int queen = 5;
const int rock = 4;
const int knight = 3;
const int bishop = 2;
const int pawn = 1;


Table::Table()
{
    Piece* p = NULL;
    Piece* _p = NULL;
    for (int i = 3; i <= 6; i++)
        for (int j = 1; j <= 8; j++)
            table[i][j] = 0;

    ///kings
    table[8][4] = king;
    table[1][4] = -king;
    p = new Piece(king, { 8,4 });
    white_pieces.push_back(p);
    _p = new Piece(-king, { 1,4 });
    black_pieces.push_back(_p);

    ///queens
    table[8][5] = queen;
    table[1][5] = -queen;
    p = new Piece(queen, { 8,5 });
    white_pieces.push_back(p);
    _p = new Piece(-king, { 1,5 });
    black_pieces.push_back(_p);

    ///rocks
    table[8][1] = table[8][8] = rock;
    table[1][1] = table[1][8] = -rock;
    p = new Piece(king, { 8,1 });
    white_pieces.push_back(p);
    _p = new Piece(-king, { 1,1 });
    black_pieces.push_back(_p);
    p = new Piece(king, { 8,8 });
    white_pieces.push_back(p);
    _p = new Piece(-king, { 1,8 });
    black_pieces.push_back(_p);

    ///knights
    table[8][2] = table[8][7] = knight;
    table[1][2] = table[1][7] = -knight;
    p = new Piece(king, { 8,2 });
    white_pieces.push_back(p);
    _p = new Piece(-king, { 1,2 });
    black_pieces.push_back(_p);
    p = new Piece(knight, { 8,7 });
    white_pieces.push_back(p);
    _p = new Piece(-knight, { 1,7 });
    black_pieces.push_back(_p);

    ///bishops
    table[8][3] = table[8][6] = bishop;
    table[1][3] = table[1][6] = -bishop;
    p = new Piece(bishop, { 8,3 });
    white_pieces.push_back(p);
    _p = new Piece(-bishop, { 8,6 });
    black_pieces.push_back(_p);
    p = new Piece(bishop, { 8,6 });
    white_pieces.push_back(p);
    _p = new Piece(-bishop, { 1,6 });
    black_pieces.push_back(_p);

    for (int i = 1; i <= 8; i++)
    {
        p = new Piece(pawn, { 7,i });
        _p = new Piece(pawn, { 2,i });

        white_pieces.push_back(p);
        black_pieces.push_back(_p);

        table[7][i] = pawn;
        table[2][i] = -pawn;
    }
}

void Table::show_table()
{
    cout << " ";
    for (int i = 1; i <= 26; i++)
        cout << "_";
    cout << "\n\n";
    for (int i = 1; i <= 8; i++)
    {
        cout << "| ";
        for (int j = 1; j <= 8; j++)
        {
            if (table[i][j] >= 0) cout << " ";
            cout << table[i][j] << " ";
        }
        cout << " |\n";
    }
    cout << " ";
    for (int i = 1; i <= 26; i++)
        cout << "_";
    cout << "\n";
}

pair<int, int> Table::get_coordinates(pair<char, int> position)
{
    return { (int)(position.first - 'a') +1 , 8 - position.second+1 };
}

bool Table::simulate_attack_table(pair<int, int> king_pos, int color) {
    int king_col = king_pos.first;
    int king_lin = king_pos.second;
    for (int col = king_pos.first, lin = king_pos.first; col <= 8 && lin <= 8 && table[lin][col] * color <= 0; col++, lin++)
        if (table[lin][col] == -color * queen || table[lin][col] == -color * bishop) { cout << "Queen or bishop on the way"; return false; }

    for (int col = king_pos.first, lin = king_pos.first; col <= 8 && lin >= 1 && table[lin][col] * color <= 0; col++, lin--)
        if (table[lin][col] == -color * queen || table[lin][col] == -color * bishop) { cout << "Queen or bishop on the way"; return false; }

    for (int col = king_pos.first, lin = king_pos.first; col >= 1 && lin <= 8 && table[lin][col] * color <= 0; col--, lin++)
        if (table[lin][col] == -color * queen || table[lin][col] == -color * bishop) { cout << "Queen or bishop on the way"; return false; }

    for (int col = king_pos.first, lin = king_pos.first; col >= 1 && lin >= 1 && table[lin][col] * color <= 0; col--, lin--)
        if (table[lin][col] == -color * queen || table[lin][col] == -color * bishop) { cout << "Queen or bishop on the way"; return false; }


    for (int col = king_pos.second; col >= 1 && table[king_lin][col] * color <= 0; col--)
        if (table[col][king_lin] == -color * queen || table[col][king_lin] == -color * rock) { cout << "Queen or rock on the way"; return false; }

    for (int col = king_pos.second; col <= 8 && table[king_lin][col] * color <= 0; col++)
        if (table[col][king_lin] == -color * queen || table[col][king_lin] == -color * rock) { cout << "Queen or rock on the way"; return false; }

    for (int lin = king_pos.second; lin >= 1 && table[lin][king_col] * -color <= 0; lin--)
        if (table[king_col][lin] == -color * queen || table[king_col][lin] == -color * rock) { cout << "Queen or rock on the way"; return false; }

    for (int lin = king_pos.second; lin <= 8 && table[lin][king_col] * -color <= 0; lin++)
        if (table[king_col][lin] == -color * queen || table[king_col][lin] == -color * rock) { cout << "Queen or rock on the way"; return false; }

    int d_lin[] = { -1,-2,-2,-1,1,2,2,1 };
    int d_col[] = { -2,-1,1,2,2,1,-1,-2 };

    for (int k = 0; k < 8; k++) {
        int lin = king_lin + d_lin[k];
        int col = king_col + d_col[k];
        if (on_table({ lin,col }))
            if (-color * table[lin][col])
            {
                cout << "Knight on the way"; return false;
            }
        return true;
    }
}


bool Table::valid_table(int color){
    if (color == 1) {
        ///white moved, white should not be in check
        pair<int, int> white_king_pos = (*white_pieces[0]).get_position();
        return simulate_attack_table(white_king_pos,1);    
    }
    else {
        ///black moved, black should not be in check
        pair<int, int> black_king_pos = (*black_pieces[0]).get_position();
        return simulate_attack_table(black_king_pos, -1);
    }
}



void Table::make_move(pair<char, int> i, pair<char, int> f, int color)
{
    pair<int, int> pos_i = get_coordinates(i);
    pair<int, int> pos_f = get_coordinates(f);

    if (!on_table(pos_i) || !on_table(pos_f))
    {
        cout << "Positions are not on the table or invalid\n";
      
    }
    switch (table[pos_i.second][pos_i.first] * color)
    {
    case king:
        king_move(pos_i, pos_f);
        break;
    case queen:
        queen_move(pos_i, pos_f);
        break;
    case rock:
        rock_move(pos_i, pos_f);
        break;
    case knight:
        knight_move(pos_i, pos_f);
        break;
    case bishop:
        bishop_move(pos_i, pos_f);
        break;
    case pawn:
        pawn_move(pos_i, pos_f);
        break;
    default:
        break;
    }

    if (!valid_table(color)) {
        cout << "Invalid table\n";
    }


}

