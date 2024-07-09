#include "Board.h"

Board::Board() {}

// ���带 �ʱ�ȭ�ϴ� �Լ�
void Board::initializeBoard() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j] = ' '; // ��� ĭ�� ��ĭ���� ����
        }
    }
}

// ���� ���� ���¸� ����ϴ� �Լ�
void Board::displayBoard() {
    system("cls"); // �ܼ�â �����
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j];
            if (j < SIZE - 1) 
                cout << "|"; // �� 
        }
        cout << endl;
        if (i < SIZE - 1) 
            cout << "-----" << endl; // ��
    }
    this_thread::sleep_for(chrono::seconds(1)); // 1�� ���
}

// �־��� �÷��̾ �¸��ߴ��� Ȯ���ϴ� �Լ�
bool Board::checkWin(char player) {
    // ��� �� �˻�
    for (int i = 0; i < SIZE; ++i) {
        // ���� ĭ���� ���� ���� 3ĭ�� �ɺ��� ������ Ȯ��
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // �밢�� �˻�
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// �־��� ��ġ�� �ɺ� ���� �Լ�
bool Board::makeMove(int row, int col, char player) {
    if (board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false;
}