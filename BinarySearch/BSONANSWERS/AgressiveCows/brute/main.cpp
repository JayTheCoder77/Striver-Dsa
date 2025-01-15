#include <bits/stdc++.h>
bool canWePlace(vector<int>&stalls,int dist,int cows){
    int countCows = 1;
    int last = stalls[0];
    for(int i = 1 ; i < stalls.size() ; i++){
      if (stalls[i] - last >= dist) {
        countCows++;
        last = stalls[i];
      }
    if(countCows >= cows) return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    int n = stalls.size();
    sort(stalls.begin(),stalls.end());
    int limit = stalls[n-1] - stalls[0];
    for(int i = 1 ; i <= limit ; i++){
        if(canWePlace(stalls,i,k) == true){
            continue;
        }
        else{
            return i - 1;
        }
    }
    return limit;
}

tc = o(n * (max-min)) + o(nlogn) for sorting