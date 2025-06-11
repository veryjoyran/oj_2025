#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> board(8, vector<char>(8, '.'));
vector<pair<int, int>> queens;

bool isSafe(int row, int col) {
    for(auto& queen : queens) {
        int r = queen.first;
        int c = queen.second;

        if(r == row) return false;

        if(c == col) return false;

        if(abs(r - row) == abs(c - col)) return false;
    }
    return true;
}


bool hasQueenInRow(int row) {
    for(auto& queen : queens) {
        if(queen.first == row) {
            return true;
        }
    }
    return false;
}

bool solve(int row) {
    if(queens.size() == 8) {
        return true;
    }

    if(row >= 8) {
        return false;
    }

    if(hasQueenInRow(row)) {
        return solve(row + 1);
    }

    for(int col = 0; col < 8; col++) {
        if(isSafe(row, col)) {
            queens.push_back({row, col});
            board[row][col] = 'Q';

            if(solve(row + 1)) {
                return true;
            }

            queens.pop_back();
            board[row][col] = '.';
        }
    }

    return false;
}

void printBoard() {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;

    for(int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        queens.push_back({r, c});
        board[r][c] = 'Q';
    }

    if(solve(0)) {
        printBoard();
    }

    return 0;
}
