#include <bits/stdc++.h> 
bool possible(vector<vector<int>>& sudoku , int row , int col , int num){
    for(int i = 0 ; i < 9 ; i++){
        if(sudoku[i][col] == num) return false;
        if(sudoku[row][i] == num) return false;
        if(sudoku[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num) return false;
    }
    return true;
}
bool solve(vector<vector<int>>& sudoku){
    for(int i = 0 ; i < sudoku.size() ; i++){
        for(int j = 0 ; j < sudoku[0].size() ; j++){
            if(sudoku[i][j] == 0){
                for(int k = 1 ; k <= 9 ; k++){
                    if(possible(sudoku,i,j,k)){
                        sudoku[i][j] = k;

                        if(solve(sudoku)) return true;
                        else sudoku[i][j] = 0;

                    }
                }
                return false;
            }
        }   
    }
    return true;
}
void solveSudoku(vector<vector<int>>& sudoku)
{
	// Write your code here
    // No need to print the final sudoku
    // Just fill the values in the given matrix
    solve(sudoku);
}

tc = o(9^81)
sc = o(81) = o(1)