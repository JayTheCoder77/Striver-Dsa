#include <bits/stdc++.h>
int boardfind(vector<int> &boards,int board, int k){
    int painters = 1;
    int boardsPainted = 0;
    for(int i = 0 ; i < boards.size() ; i++){
        if(boards[i] + boardsPainted > board){
            painters += 1;
            boardsPainted = boards[i];
        }
        else{
            boardsPainted += boards[i];
        }
    }
    return painters;
}
int findmax(vector<int> &boards){
    int maxi = INT_MIN;
    for(int i = 0 ; i < boards.size() ; i++){
        maxi = max(maxi,boards[i]);
    }
    return maxi;
}
int findsum(vector<int> &boards){
    int sum = 0;
    for(int i = 0 ; i < boards.size() ; i++){
        sum += boards[i];
    }
    return sum;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int max = findmax(boards); // low
    int sum = findsum(boards); // high
    int numofpainters = 0;
    for(int i = max ; i <= sum ; i++){
        boardsPainted = boardfind(boards,i,k);
        if(numofpainters <= k) return i;
    }
    return -1;
}

// finding min(max) same as allocate books,split array largest sum

tc = o(n) sum + o(n) max + o(n * (sum - max + 1))