#pragma once
#include <iostream>


using namespace std;

struct pos {
    int lin, col;
};


class Piece {
    int value;
    pos position;
    bool beaten;
public:
    Piece(int, pair<int,int>);
    bool is_beaten() {
        return beaten;
    }
    void set_beaten() {
        beaten = true;
    }
    pos get_position() {
        return position;
    }
    void set_position(pos posit) {
        position = posit;
    }

    void set_value(int new_value) {
        if (abs(value) == 1)
            value = new_value;
    }
    int get_value() {
        return value;
    }
};
