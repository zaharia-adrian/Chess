#pragma once
#include "table.h"
#include "piece.h"

Table::Table()
{
	Piece* p = NULL;
	Piece* _p = NULL;
	for (int i = 3; i <= 6; i++)
		for (int j = 1; j <= 8; j++)
			table[i][j] = 0;

	///kings
	table[8][5] = king;
	table[1][5] = -king;
	p = new Piece(king, { 8,5 });
	white_pieces.push_back(p);
	_p = new Piece(-king, { 1,5 });
	black_pieces.push_back(_p);

	///queens
	table[8][4] = queen;
	table[1][4] = -queen;
	p = new Piece(queen, { 8,4 });
	white_pieces.push_back(p);
	_p = new Piece(-king, { 1,4 });
	black_pieces.push_back(_p);

	///rocks
	table[8][1] = table[8][8] = rook;
	table[1][1] = table[1][8] = -rook;
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

pos Table::get_coordinates(pair<char, int> position)
{
	pos pos;
	pos.lin = 8 - position.second + 1;
	pos.col = (int)(position.first - 'a') + 1;
	return pos;
}

