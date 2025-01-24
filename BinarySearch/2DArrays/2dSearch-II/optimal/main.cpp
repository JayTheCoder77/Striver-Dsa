class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0 , col = m - 1;
        while(row < n && col >= 0){
            if(matrix[row][col] == target) return true; // return {row , col}
            else if(matrix[row][col] < target) row++;
            else col--;
        }
        return false; // return {-1,-1};
    }
};

tc = o(n + m)  going from one corner to another PS :  we dont move diagonally or in a hypotenuse manner