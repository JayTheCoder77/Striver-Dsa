#include <bits/stdc++.h>
vector<int> findPeakGrid(vector<vector<int>> &g){
    // Write your code here.  
    // better - just return the largest element
    int largest = INT_MIN;
    int row = -1 , col = -1;
    int n = g.size();
    int m = g[0].size();
    for(int i = 0 ; i < n ; i++){
      for (int j = 0; j < m; j++) {
        if (g[i][j] > largest) {
          largest = g[i][j];
          row = i;
          col = j;
        }
      }
    }
      return {row,col};
}

tc = o(n * m)