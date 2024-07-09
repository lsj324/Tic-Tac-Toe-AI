#include "Player.h"
#include <iostream>

Player::Player(char s, Board* b) : symbol(s), board(b) {
    A1_9_initial();
}

void Player::A1_9_initial() {
    for (int i = 0; i < 9; ++i) {
        A1_9[i] = 0;
    }
}

void Player::A1_9_modification(int i) {
    A1_9[i - 1] = 1;
}

char Player::findSymbol() const {
    return symbol;
}

tuple<int, int> Player::bestMove() {
    string choice;
    tuple<int, int> bestMove = { -1, -1 };

    while (true)
    {
        cout << "------------------" << endl;
        cout << "원하는 칸을 선택(A1~A9): ";
        cin >> choice;
        cout << choice << "칸으로 " << symbol << " 넣기" << endl;
        cout << "------------------" << endl;

        if (choice == "A1" && A1_9[0] == 0) {
            A1_9_modification(1);
            bestMove = { 0, 0 };
            return bestMove;
        }
        else if (choice == "A2" && A1_9[1] == 0) {
            A1_9_modification(2);
            bestMove = { 0, 1 };
            return bestMove;
        }
        else if (choice == "A3" && A1_9[2] == 0) {
            A1_9_modification(3);
            bestMove = { 0, 2 };
            return bestMove;
        }
        else if (choice == "A4" && A1_9[3] == 0) {
            A1_9_modification(4);
            bestMove = { 1, 0 };
            return bestMove;
        }
        else if (choice == "A5" && A1_9[4] == 0) {
            A1_9_modification(5);
            bestMove = { 1, 1 };
            return bestMove;
        }
        else if (choice == "A6" && A1_9[5] == 0) {
            A1_9_modification(6);
            bestMove = { 1, 2 };
            return bestMove;
        }
        else if (choice == "A7" && A1_9[6] == 0) {
            A1_9_modification(7);
            bestMove = { 2, 0 };
            return bestMove;
        }
        else if (choice == "A8" && A1_9[7] == 0) {
            A1_9_modification(8);
            bestMove = { 2, 1 };
            return bestMove;
        }
        else if (choice == "A9" && A1_9[8] == 0) {
            A1_9_modification(9);
            bestMove = { 2, 2 };
            return bestMove;
        }
        else {
            cout << endl;
            cout << "정확한 칸 번호(A1~A9)를 입력하세요" << endl;
            cout << endl;
        }
    }
}
