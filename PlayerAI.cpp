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

    // 승리할 수 있는 즉시 이동 찾기
    for (int i = 0; i < board->SIZE; ++i) {
        for (int j = 0; j < board->SIZE; ++j) {
            if (board->board[i][j] == ' ') {
                // 내 심볼이 이기는 칸 찾기
                board->board[i][j] = symbol;
                if (board->checkWin(symbol)) {
                    board->board[i][j] = ' ';
                    return { i, j };
                }
                board->board[i][j] = ' ';

                // 적 심볼이 이기는 칸 찾기
                board->board[i][j] = opponent;
                if (board->checkWin(opponent)) {
                    board->board[i][j] = ' ';
                    return { i, j };
                }
                board->board[i][j] = ' ';
            }
        }
    }

    // 가장 좋은 점수를 얻을 수 있는 이동 찾기
    for (int i = 0; i < board->SIZE; ++i) {
        for (int j = 0; j < board->SIZE; ++j) {

            if (board->board[i][j] == ' ') {
                board->board[i][j] = symbol;
                int score = 0;
                for (int k = 0; k < board->SIZE; ++k) {
                    if (board->board[i][k] == symbol) 
                        score++; // 행 점수 계산
                    if (board->board[k][j] == symbol) 
                        score++; // 열 점수 계산
                }
                if (i == j) {
                    for (int k = 0; k < board->SIZE; ++k) {
                        if (board->board[k][k] == symbol) 
                            score++; // 대각선 점수 계산
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
