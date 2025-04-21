class Solution {
    public:
      int celebrity(vector<vector<int> >& mat) {
          // code here
          int n = mat.size();
          int top = 0 , down = n-1;
          while(top < down){
              if(mat[down][top] == 1) down--;
              else if(mat[top][down] == 1) top++;
              else{
                  top++;
                  down--;
              }
          }
          if(top > down) return -1;
          // top == down
          for(int i = 0 ; i < n ; i++){
              if(top == i) continue;
              if(mat[top][i] == 1 || mat[i][top] == 0) return -1;
          }
          return top;
      }
  };

  tc = o(2n)
  sc = o(1)