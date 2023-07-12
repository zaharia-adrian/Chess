#pragma once
#include "piece.h"
#include "../table/table.h"

Piece::Piece(int val, pair<int,int> pos) {
    value = val;
    position.lin = pos.first;
    position.col = pos.second;
    beaten = false;
}

