#pragma once
#include "table.h"
#include "../piece/piece.h"

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

void Table::draw_table(sf::RenderWindow &window, pos p, sf::Font f) {
	sf::RectangleShape board(sf::Vector2f(square_size * 9, square_size * 9));
	board.setFillColor(sf::Color(122, 63, 33, 255));
	board.setPosition(sf::Vector2f(margin_left - square_size / 2, margin_top - square_size / 2));

	window.draw(board);

	for (int i = 0; i <= 8; i++) {
		if (i == 8) {
			for (int j = 1; j <= 8; j++) {

				sf::Text letter((char)('a' + j - 1), f);
				letter.setFillColor(sf::Color::White);
				float position_x = (j - 1) * square_size + square_size / 2 + margin_left - letter.getCharacterSize() / 4.f;
				float position_y = i * square_size + margin_top;
				letter.setPosition(sf::Vector2f(position_x, position_y));

				window.draw(letter);
			}
			break;
		}
		for (int j = 0; j <= 8; j++) {

			if (j == 0) {
				sf::Text digit((char)(8 - i + '0'), f);

				digit.setFillColor(sf::Color::White);
				float position_x = margin_left - square_size / 4.f - digit.getCharacterSize() / 4.f;
				float position_y = i * square_size + margin_top + digit.getCharacterSize();
				digit.setPosition(sf::Vector2f(position_x, position_y));

				window.draw(digit);
				continue;

			}
			sf::RectangleShape square(sf::Vector2f(square_size, square_size));

			((i + j - 1) % 2 == 0) ? square.setFillColor(sf::Color(230, 212, 183, 255)) : square.setFillColor(sf::Color(135, 58, 14, 255));
			square.setPosition(sf::Vector2f((j - 1) * square_size + margin_left, i * square_size + margin_top));

			window.draw(square);
		}
	}
	///draw pieces
	int piece;
	for (int lin = 1; lin <= 8; lin++)
		for (int col = 1; col <= 8; col++) {
			piece = get_value(lin, col);
			draw_piece(window, piece, { lin,col }, { p.lin,p.col }, square_size);
		}
}
void Table::draw_piece(sf::RenderWindow& window, int piece, pos pos_piece, pos pos_select, float square_size) {
	if (piece != 0) {
		sf::Texture p;
		string path;
		switch (piece) {
		case king:
			path = "Pieces/king_w.png";
			break;
		case -king:
			path = "Pieces/king_b.png";
			break;
		case queen:
			path = "Pieces/queen_w.png";
			break;
		case -queen:
			path = "Pieces/queen_b.png";
			break;
		case rook:
			path = "Pieces/rook_w.png";
			break;
		case -rook:
			path = "Pieces/rook_b.png";
			break;
		case knight:
			path = "Pieces/knight_w.png";
			break;
		case -knight:
			path = "Pieces/knight_b.png";
			break;
		case bishop:
			path = "Pieces/bishop_w.png";
			break;
		case -bishop:
			path = "Pieces/bishop_b.png";
			break;
		case pawn:
			path = "Pieces/pawn_w.png";
			break;
		case -pawn:
			path = "Pieces/pawn_b.png";
			break;
		default:
			break;
		}
		if (!p.loadFromFile(path)) cout << "Unable to load piece with value=" << piece << "\n";
		sf::Sprite P(p);
		if (pos_piece.lin == pos_select.lin && pos_piece.col == pos_select.col) P.scale(1.1f, 1.1f);
		P.setPosition(sf::Vector2f(pos_piece.col * square_size + 115.f, pos_piece.lin * square_size + 60.f));
		window.draw(P);
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

