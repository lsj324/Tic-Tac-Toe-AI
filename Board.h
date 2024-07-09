#pragma once
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

class Board {
public:
	static const int SIZE = 3;
	char board[SIZE][SIZE];


	Board();

	// ���带 �ʱ�ȭ�ϴ� �Լ�
	void initializeBoard();

	// ���� ���� ���¸� ����ϴ� �Լ�
	void displayBoard();

	// �־��� �÷��̾ �¸��ߴ��� Ȯ���ϴ� �Լ�
	bool checkWin(char player);

	// �־��� ��ġ�� �÷��̾��� ��ȣ�� ���� �Լ�
	bool makeMove(int row, int col, char player);
};

