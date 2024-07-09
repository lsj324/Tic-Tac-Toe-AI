#include "Board.h"
#include "Player.h"
#include "PlayerAI.h"

// 메인 함수 (게임 루프 포함)
int main() {
    Board board; // 보드 객체 생성
    Player playerO('o', &board); // 'o' 플레이어 객체 생성
    PlayerAI playerX('x', &board); // 'x' 플레이어 객체 생성

    board.initializeBoard(); // 보드 초기화
    int currentPlayer = 0; // 현재 플레이어 (0: 'o', 1: 'x')
    bool game_over = false;


    while (true) {
        board.displayBoard(); // 현재 보드 상태 표시

        // 현재 플레이어 결정
        if (currentPlayer == 0) {
            auto [row, col] = playerO.bestMove(); // 최적의 이동 계산
            if (row != -1 && col != -1) { // 유효한 이동인 경우
                board.makeMove(row, col, playerO.findSymbol()); // 최적의 위치로 이동
            }
            else {
                cout << "No valid moves left!" << endl;
            }

            if (board.checkWin(playerO.findSymbol())) { // 승리 여부 확인
                board.displayBoard();
                cout << "--------------------" << endl;
                cout << "Player " << playerO.findSymbol() << " wins!" << endl;
                cout << "--------------------" << endl;
                game_over = true;
            }
        }
        else {
            auto [row, col] = playerX.bestMove(); // 최적의 이동 계산
            if (row != -1 && col != -1) { // 유효한 이동인 경우
                board.makeMove(row, col, playerX.findSymbol()); // 최적의 위치로 이동
            }
            else {
                std::cout << "No valid moves left!" << std::endl;
            }

            if (board.checkWin(playerX.findSymbol())) { // 승리 여부 확인
                board.displayBoard();
                cout << "--------------------" << endl;
                cout << "Player " << playerX.findSymbol() << " wins!" << endl;
                cout << "--------------------" << endl;
                game_over = true;
            }
        }

        if (!game_over) {
            currentPlayer = 1 - currentPlayer; // 플레이어 전환
            bool draw = true;
            for (int i = 0; i < Board::SIZE; ++i) {
                for (int j = 0; j < Board::SIZE; ++j) {
                    if (board.board[i][j] == ' ') { // 빈칸이 있는지 확인
                        draw = false;
                        break;
                    }
                }
                if (!draw) break;
            }
            if (draw) { // 무승부 여부 확인
                board.displayBoard();
                cout << "--------------------" << endl;
                std::cout << "Draw" << std::endl;
                cout << "--------------------" << endl;
                cout << endl;
                game_over = true;
            }
        }

        if (game_over) {
            int gameStop;
            cout << "--------------------" << endl;
            cout << "다시시작 : 1" << endl;
            cout << "그만하기 : 2" << endl;
            cout << "--------------------" << endl;
            cout << "입력 : ";
            cin >> gameStop;

            board.initializeBoard(); // 보드 초기화
            currentPlayer = 0;
            playerO.A1_9_initial();
            game_over = false;

            if (gameStop == 1)
                continue;
            else if (gameStop == 2)
                break;
        }
    }

    return 0;
}
