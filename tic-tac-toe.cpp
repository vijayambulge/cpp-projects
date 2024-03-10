#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printBoard(const vector<vector<char>>& board) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

bool checkWin(const vector<vector<char>>& board, char player) {
    
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); 
    int row, col;
    char currentPlayer = 'X';
    bool isGameOver = false;

    cout << "Welcome to Tic Tac Toe!" << endl;

    while (!isGameOver) {
        printBoard(board);
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;

            if (checkWin(board, currentPlayer)) {
                printBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                isGameOver = true;
            }
            else if (board[0][0] != ' ' && board[0][1] != ' ' && board[0][2] != ' ' &&
                     board[1][0] != ' ' && board[1][1] != ' ' && board[1][2] != ' ' &&
                     board[2][0] != ' ' && board[2][1] != ' ' && board[2][2] != ' ') {
                printBoard(board);
                cout << "It's a draw!" << endl;
                isGameOver = true;
            }
            else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }
        else {
            cout << "Invalid move! Try again." << endl;
        }
    }

    return 0;
}
