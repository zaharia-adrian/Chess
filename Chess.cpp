
#include "table.h"
#include <SFML/Graphics.hpp>
#include <vector>

using std::pair;
using std::cin;
using std::vector;

int turn = 1;
int white_time = 160;
int black_time = 160;

float square_size = 90.f;
float margin_top = 150.f;
float margin_left = 200.f;

bool has_initial_pos = false;
int lin_p, col_p;

int main() {

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "CHESS GAME", sf::Style::Default);

	Table T;
	pair<char, int> pos_i;
	pair<char, int> pos_f;

	///main font
	sf::Font f;
	f.loadFromFile("Fonts/Century.TTF");

	///board
	sf::RectangleShape board(sf::Vector2f(square_size * 9, square_size * 9));
	board.setFillColor(sf::Color(122, 63, 33, 255));
	board.setPosition(sf::Vector2f(margin_left - square_size / 2, margin_top - square_size / 2));

	cout << "White moves\n";
	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				window.close();

			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
				int pos_x = event.mouseButton.x;
				int pos_y = event.mouseButton.y;

				if (pos_x >= margin_left &&
					pos_x <= margin_left + 8 * square_size &&
					pos_y >= margin_top &&
					pos_y <= margin_top + 8 * square_size
					) {

					if (has_initial_pos) {
						pos_f.first = char('a' + (pos_x - margin_left) / square_size);
						pos_f.second = 8 - (pos_y - margin_top) / square_size + 1;
						cout << pos_f.first << " " << pos_f.second << "\n";

						if (T.make_move(pos_i, pos_f, turn))
							turn = -turn;
						(turn == 1) ? cout << "White moves\n" : cout << "Black moves\n";
						has_initial_pos = false;
					}
					else {
						pos_i.first = char('a' + (pos_x - margin_left) / square_size);
						pos_i.second = 8 - (pos_y - margin_top) / square_size + 1;
						lin_p = 8 - pos_i.second + 1;
						col_p = (int)(pos_i.first - 'a') + 1;
						cout << pos_i.first << " " << pos_i.second << "\n";
						has_initial_pos = true;
					}
				}
			}
		}

		window.clear(sf::Color(26, 26, 26, 255));

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
		for (int lin = 1; lin <= 8; lin++) {
			for (int col = 1; col <= 8; col++) {
				piece = T.get_value(lin, col);
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
					if (lin == lin_p && col == col_p) P.scale(1.1f, 1.1f);
					P.setPosition(sf::Vector2f(col * square_size + 115.f, lin * square_size + 60.f));
					window.draw(P);
				}
			}
		}
		window.display();
	}
	return 0;
}