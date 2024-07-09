#pragma once
#include "Board.h"
#include <tuple>

using namespace std;

class PlayerAI {
private:
    char symbol;
    Board* board; // Board 클래스의 포인터

public:
    PlayerAI(char s, Board* b);
    char findSymbol() const;
    tuple<int, int> bestMove() const;
};
