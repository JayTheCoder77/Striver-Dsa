#include <bits/stdc++.h>
int largestInCol(vector<vector<int>>&g,int n,int col){
    int largest = INT_MIN;
    int index = -1;
    for(int i = 0 ; i < n ; i++){
      if (g[i][col] > largest) {
        largest = g[i][col];
        index = i;
        }
      }
      return index;
}
vector<int> findPeakGrid(vector<vector<int>> &g){
    // Write your code here.
    int n = g.size();
    int m = g[0].size();
    int low = 0;
    int high = m - 1;
    while(low <= high){
      int mid = (low + high) / 2;
      int maxRowIndex = largestInCol(g,n,mid);
      int left = (mid - 1 >= 0) ? g[maxRowIndex][mid-1] : INT_MIN;
      int right = (mid + 1 < m) ? g[maxRowIndex][mid+1] : INT_MIN;
      if(g[maxRowIndex][mid] > left && g[maxRowIndex][mid] > right) return {maxRowIndex,mid};
      else if(g[maxRowIndex][mid] < left) high = mid - 1;
      else low = mid + 1;
    }
    return {-1,-1};  
}

tc = o(n * log2m)