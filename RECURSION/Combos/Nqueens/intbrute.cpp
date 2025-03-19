#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &board, int n) {
    int r = row, c = col;
    
    // Check upper diagonal
    while (r >= 0 && c >= 0) {
        if (board[r][c] == 1) return false;
        r--, c--;
    }

    // Check left side
    r = row, c = col;
    while (c >= 0) {
        if (board[r][c] == 1) return false;
        c--;
    }

    // Check lower diagonal
    r = row, c = col;
    while (r < n && c >= 0) {
        if (board[r][c] == 1) return false;
        r++, c--;
    }

    return true;
}

void solve(int col, vector<vector<int>> &board, vector<vector<int>> &ans, int n) {
    if (col == n) {
        vector<int> solution;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                solution.push_back(board[i][j]); // Store board as 1D array
            }
        }
        ans.push_back(solution);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 1;
            solve(col + 1, board, ans, n);
            board[row][col] = 0; // Backtrack
        }
    }
}

vector<vector<int>> nQueens(int n) {
    vector<vector<int>> ans;
    vector<vector<int>> board(n, vector<int>(n, 0));
    solve(0, board, ans, n);
    return ans;
}