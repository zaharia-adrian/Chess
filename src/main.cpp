
#include <SFML/Graphics.hpp>
#include <vector>

#include "table/table.h"
#include "piece/piece.h"




using std::pair;
using std::cin;
using std::vector;

int turn = 1;
int white_time = 160;
int black_time = 160;

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

		T.draw_table(window, { lin_p,col_p }, f);

		window.display();
	}
	return 0;
}