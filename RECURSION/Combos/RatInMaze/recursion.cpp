#include <bits/stdc++.h>
void search(int i,int j , vector < vector < int >> & arr , int n , vector<string> &ans,string move,vector<vector<int>> &visit){
 if(i == n-1 && j == n-1){
     ans.push_back(move);
     return;
 }
    // downwards
    if(i+1 < n && !visit[i+1][j] && arr[i+1][j] == 1){
        visit[i][j] = 1;
        search(i+1,j,arr,n,ans,move + 'D' , visit);
        visit[i][j] = 0;
    }
    // left
    if(j-1 >= 0 && !visit[i][j-1] && arr[i][j-1] == 1){
        visit[i][j] = 1;
        search(i,j-1,arr,n,ans,move + 'L' , visit);
        visit[i][j] = 0;
    }
    // right
    if(j+1 < n && !visit[i][j+1] && arr[i][j+1] == 1){
        visit[i][j] = 1;
        search(i,j+1,arr,n,ans,move + 'R' , visit);
        visit[i][j] = 0;
    }
    // up
    if(i-1 >= 0 && !visit[i-1][j] && arr[i-1][j] == 1){
        visit[i][j] = 1;
        search(i-1,j,arr,n,ans,move + 'U' , visit);
        visit[i][j] = 0;
    }
} 
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.
    vector<string> ans;
    vector<vector<int>> visit(n,vector<int>(n,0));
    if(arr[0][0] == 1) search(0,0,arr,n,ans,"",visit);
    // lexicographic order DLRU
    return ans;
}

tc = o(4 ^ (m * n))
sc = o(m * n)