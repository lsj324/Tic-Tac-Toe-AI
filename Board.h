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

	// 보드를 초기화하는 함수
	void initializeBoard();

	// 현재 보드 상태를 출력하는 함수
	void displayBoard();

	// 주어진 플레이어가 승리했는지 확인하는 함수
	bool checkWin(char player);

	// 주어진 위치에 플레이어의 기호를 놓는 함수
	bool makeMove(int row, int col, char player);
};

