#pragma once
#include <iostream>
using std::pair;
using std::cout;

class Piece {
private:
    int value;
    pair<int, int> position;
    bool beaten = false;
public:
    Piece(int, pair<int, int>);
    bool is_beaten() {
        return beaten;
    }
    void set_beatean() {
        beaten = true;
    }
    pair<int, int> get_position() {
        return position;
    }

    void set_value(int new_value) {
        if (abs(value) == 1)
            value = new_value;
    }
    int get_value() {
        return value;
    }
};
