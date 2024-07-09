#include "PlayerAI.h"
#include <ctime>
#include <random>

PlayerAI::PlayerAI(char s, Board* b) : symbol(s), board(b) {}

char PlayerAI::findSymbol() const {
    return symbol;
}

tuple<int, int> PlayerAI::bestMove() const {
    int bestScore = -1;
    tuple<int, int> bestMove = { -1, -1 };

    char opponent = (symbol == 'o') ? 'x' : 'o';

    // �¸��� �� �ִ� ��� �̵� ã��
    for (int i = 0; i < board->SIZE; ++i) {
        for (int j = 0; j < board->SIZE; ++j) {
            if (board->board[i][j] == ' ') {
                // �� �ɺ��� �̱�� ĭ ã��
                board->board[i][j] = symbol;
                if (board->checkWin(symbol)) {
                    board->board[i][j] = ' ';
                    return { i, j };
                }
                board->board[i][j] = ' ';

                // �� �ɺ��� �̱�� ĭ ã��
                board->board[i][j] = opponent;
                if (board->checkWin(opponent)) {
                    board->board[i][j] = ' ';
                    return { i, j };
                }
                board->board[i][j] = ' ';
            }
        }
    }

    // ���� ���� ������ ���� �� �ִ� �̵� ã��
    for (int i = 0; i < board->SIZE; ++i) {
        for (int j = 0; j < board->SIZE; ++j) {

            if (board->board[i][j] == ' ') {
                board->board[i][j] = symbol;
                int score = 0;
                for (int k = 0; k < board->SIZE; ++k) {
                    if (board->board[i][k] == symbol) 
                        score++; // �� ���� ���
                    if (board->board[k][j] == symbol) 
                        score++; // �� ���� ���
                }
                if (i == j) {
                    for (int k = 0; k < board->SIZE; ++k) {
                        if (board->board[k][k] == symbol) 
                            score++; // �밢�� ���� ���
                    }
                }
                if (i + j == board->SIZE - 1) {
                    for (int k = 0; k < board->SIZE; ++k) {
                        if (board->board[k][board->SIZE - k - 1] == symbol) 
                            score++;
                    }
                }
                board->board[i][j] = ' ';

                mt19937 rng(time(nullptr));
                uniform_int_distribution<int> dist(0, 2);

                if (score == bestScore) {
                    while (true) {
                        int random_i = dist(rng);
                        int random_j = dist(rng);

                        if (board->board[random_i][random_j] == ' ') {
                            bestMove = { random_i, random_j };
                            return bestMove;
                        }
                    }
                }
                else if (score > bestScore) {
                    bestScore = score;
                    bestMove = { i, j };
                }
            }
        }
    }
    return bestMove;
}
