
#include "table.h"
#include <SFML/Graphics.hpp>
#include <vector>

using std::pair;
using std::cin;
using std::vector;

int turn = 1;

float square_size = 90.f;
float margin_top = 150.f;
float margin_left = 200.f;

int main() {

	sf::Font f;
	f.loadFromFile("Fonts/Century.TTF");

	sf::Texture pawn_b;
	pawn_b.loadFromFile("Pieces/bishop_b.png");
	sf::Sprite sprite(pawn_b);
	sprite.setPosition(sf::Vector2f(200.f,150.f));

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML_LINK", sf::Style::Default);

	sf::RectangleShape board(sf::Vector2f(square_size * 9, square_size * 9));

	board.setFillColor(sf::Color(122, 63, 33, 255));
	board.setPosition(sf::Vector2f(margin_left-square_size/2,margin_top-square_size/2));

	while (window.isOpen()) {
 
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				window.close();		
		}
		window.clear(sf::Color(26, 26, 26, 255));


	
		window.draw(board);

		for (int i = 0; i <= 8; i++) {
			if (i == 8) {
				for (int j = 1; j <= 8; j++) {

					sf::Text letter((char)('a' + j - 1),f);
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
					float position_x = margin_left - square_size / 4.f  - digit.getCharacterSize() / 4.f;
					float position_y = i * square_size + margin_top + digit.getCharacterSize();
					digit.setPosition(sf::Vector2f(position_x, position_y));

					window.draw(digit);
					continue;

				}
				sf::RectangleShape square(sf::Vector2f(square_size, square_size));

				((i + j  - 1) % 2 == 0) ? square.setFillColor(sf::Color(230, 212, 183, 255)) : square.setFillColor(sf::Color(135,58,14,255));
				square.setPosition(sf::Vector2f((j-1) * square_size + margin_left, i * square_size + margin_top));

				window.draw(square);
			}
		}
		window.draw(sprite);
		window.display();
	}
	return 0;
}


//int main()
//{
//        Table t;
//    
//        pair<char,int> pos_i;
//        pair<char,int> pos_f;
//        t.show_table();
//        while(1){
//            if (turn == 1)
//                cout << "White moves\n";
//            else
//                cout << "Black moves\n";
//            cout << "Cititi coordontaele initiale\n";
//            cin >> pos_i.first>>pos_i.second;
//            cout << "Cititi coordonatele finale\n";
//            cin >> pos_f.first >> pos_f.second;
//            
//            t.make_move(pos_i,pos_f,turn);
//            t.show_table();
//            turn=-turn;
//        }
//    return 0;
//}




///TABLA

///  4  3  2  6  5  2  3  4
///  1  1  1  1  1  1  1  1
///  0  0  0  0  0  0  0  0
///  0  0  0  0  0  0  0  0
///  0  0  0  0  0  0  0  0
///  0  0  0  0  0  0  0  0
/// -1 -1 -1 -1 -1 -1 -1 -1
/// -4 -3 -2 -6 -5 -2 -3 -4
