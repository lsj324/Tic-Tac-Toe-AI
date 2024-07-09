#pragma once
#include "Board.h"
#include <tuple>


class Player {
private:
    int A1_9[9];
    char symbol;
    Board* board;

public:
    Player(char s, Board* b);
    void A1_9_initial();
    void A1_9_modification(int i);
    char findSymbol() const;
    tuple<int, int> bestMove();
};
