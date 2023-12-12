#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

const int SIZE = 15; // 오목판 크기

enum Stone {
    EMPTY,
    PLAYER,
    COMPUTER
};

struct Move {
    int row;
    int col;
};

class OmokGame {
public:
    OmokGame() : currentPlayer(PLAYER), board(SIZE, vector<Stone>(SIZE, EMPTY)) {}

    void displayBoard() const {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                switch (board[i][j]) {
                    case EMPTY:
                        cout << ".";
                        break;
                    case PLAYER:
                        cout << "X";
                        break;
                    case COMPUTER:
                        cout << "O";
                        break;
                }
                cout << " ";
            }
            cout << endl;
        }
    }

    bool isMoveValid(int row, int col) const {
        return row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == EMPTY;
    }

    bool makeMove(int row, int col, Stone player) {
        if (isMoveValid(row, col)) {
            board[row][col] = player;
            return true;
        }
        return false;
    }

    bool isGameOver() const {
        return checkWin() || checkTie();
    }

    bool checkWin() const {
        // TODO: 구현해야 함
        return false;
    }

    bool checkTie() const {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (board[i][j] == EMPTY) {
                    return false;
                }
            }
        }
        return true;
    }

    Move getPlayerMove() const {
        int row, col;
        cout << "Enter your move (row and column, e.g., 1 2): ";
        cin >> row >> col;
        return {row - 1, col - 1};
    }

    Move getComputerMove() const {
        // TODO: 구현해야 함
        int row = rand() % SIZE;
        int col = rand() % SIZE;
        return {row, col};
    }

    void play() {
        while (!isGameOver()) {
            displayBoard();

            Move move;
            if (currentPlayer == PLAYER) {
                move = getPlayerMove();
            } else {
                move = getComputerMove();
            }

            if (makeMove(move.row, move.col, currentPlayer)) {
                currentPlayer = (currentPlayer == PLAYER) ? COMPUTER : PLAYER;
            } else {
                cout << "Invalid move. Try again.\n";
            }
        }

        displayBoard();
        if (checkWin()) {
            cout << "Player " << ((currentPlayer == PLAYER) ? "X" : "O") << " wins!\n";
        } else {
            cout << "It's a tie!\n";
        }
    }

private:
    Stone currentPlayer;
    vector<vector<Stone>> board;
};

int main() {
    srand(time(nullptr)); // 난수 생성을 위한 초기화

    OmokGame game;
    game.play();

    return 0;
}
