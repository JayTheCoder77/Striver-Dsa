class Solution {
    public:
        bool isSafe(int row , int col , vector<string> &board,int n){
            // upper diagonal
            int r = row , c = col;
            while(r >= 0 && c >= 0){
                if(board[r][c] == 'Q') return false;
                r--;
                c--;
            }
            // left
            r = row , c = col;
            while(c >= 0){
                if(board[r][c] == 'Q') return false;
                c--;
            }
            // lower diagonal
            r = row , c = col;
            while(r < n && c >= 0){
                if(board[r][c] == 'Q') return false;
                r++;
                c--;
            }
            return true;
        }
        void solve(int col , vector<vector<string>> &ans,vector<string> &board,int n){
            if(col == n){
                ans.push_back(board);
                return;
            }
            for(int i = 0 ; i < n ; i++){
                if(isSafe(i,col,board,n)){
                    board[i][col] = 'Q';
                    solve(col+1 , ans,board,n);
                    board[i][col] = '.';
                }
            }
        }
        int totalNQueens(int n) {
            vector<vector<string>> ans;
            vector<string> board(n);
            string s(n , '.');
            for(int i = 0 ; i < n ; i++) board[i] = s;
            solve(0,ans,board,n);
            return ans.size();
        }
    };