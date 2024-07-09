#include "Board.h"
#include "Player.h"
#include "PlayerAI.h"

// ���� �Լ� (���� ���� ����)
int main() {
    Board board; // ���� ��ü ����
    Player playerO('o', &board); // 'o' �÷��̾� ��ü ����
    PlayerAI playerX('x', &board); // 'x' �÷��̾� ��ü ����

    board.initializeBoard(); // ���� �ʱ�ȭ
    int currentPlayer = 0; // ���� �÷��̾� (0: 'o', 1: 'x')
    bool game_over = false;


    while (true) {
        board.displayBoard(); // ���� ���� ���� ǥ��

        // ���� �÷��̾� ����
        if (currentPlayer == 0) {
            auto [row, col] = playerO.bestMove(); // ������ �̵� ���
            if (row != -1 && col != -1) { // ��ȿ�� �̵��� ���
                board.makeMove(row, col, playerO.findSymbol()); // ������ ��ġ�� �̵�
            }
            else {
                cout << "No valid moves left!" << endl;
            }

            if (board.checkWin(playerO.findSymbol())) { // �¸� ���� Ȯ��
                board.displayBoard();
                cout << "--------------------" << endl;
                cout << "Player " << playerO.findSymbol() << " wins!" << endl;
                cout << "--------------------" << endl;
                game_over = true;
            }
        }
        else {
            auto [row, col] = playerX.bestMove(); // ������ �̵� ���
            if (row != -1 && col != -1) { // ��ȿ�� �̵��� ���
                board.makeMove(row, col, playerX.findSymbol()); // ������ ��ġ�� �̵�
            }
            else {
                std::cout << "No valid moves left!" << std::endl;
            }

            if (board.checkWin(playerX.findSymbol())) { // �¸� ���� Ȯ��
                board.displayBoard();
                cout << "--------------------" << endl;
                cout << "Player " << playerX.findSymbol() << " wins!" << endl;
                cout << "--------------------" << endl;
                game_over = true;
            }
        }

        if (!game_over) {
            currentPlayer = 1 - currentPlayer; // �÷��̾� ��ȯ
            bool draw = true;
            for (int i = 0; i < Board::SIZE; ++i) {
                for (int j = 0; j < Board::SIZE; ++j) {
                    if (board.board[i][j] == ' ') { // ��ĭ�� �ִ��� Ȯ��
                        draw = false;
                        break;
                    }
                }
                if (!draw) break;
            }
            if (draw) { // ���º� ���� Ȯ��
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
            cout << "�ٽý��� : 1" << endl;
            cout << "�׸��ϱ� : 2" << endl;
            cout << "--------------------" << endl;
            cout << "�Է� : ";
            cin >> gameStop;

            board.initializeBoard(); // ���� �ʱ�ȭ
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
