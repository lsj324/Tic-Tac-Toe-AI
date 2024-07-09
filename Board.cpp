#include "Board.h"

Board::Board() {}

// 보드를 초기화하는 함수
void Board::initializeBoard() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j] = ' '; // 모든 칸을 빈칸으로 설정
        }
    }
}

// 현재 보드 상태를 출력하는 함수
void Board::displayBoard() {
    system("cls"); // 콘솔창 지우기
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j];
            if (j < SIZE - 1) 
                cout << "|"; // 열 
        }
        cout << endl;
        if (i < SIZE - 1) 
            cout << "-----" << endl; // 행
    }
    this_thread::sleep_for(chrono::seconds(1)); // 1초 대기
}

// 주어진 플레이어가 승리했는지 확인하는 함수
bool Board::checkWin(char player) {
    // 행과 열 검사
    for (int i = 0; i < SIZE; ++i) {
        // 현재 칸에서 가로 세로 3칸의 심볼이 같은지 확인
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // 대각선 검사
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// 주어진 위치에 심볼 놓는 함수
bool Board::makeMove(int row, int col, char player) {
    if (board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false;
}