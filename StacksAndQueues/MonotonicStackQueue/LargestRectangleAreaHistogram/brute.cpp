#include<bits/stdc++.h>
vector<int> pse(vector < int > & arr){
    int n = arr.size();
    vector<int> ans(n,-1);
    stack<int> s;
    for(int i = 0 ; i < n ; i++){
      while(!s.empty() && arr[s.top()] >= arr[i]){
        s.pop();
      }
      ans[i] = s.empty() ? -1 : s.top();
      s.push(i);
    }
    return ans;
}
vector<int> nse(vector < int > & arr){
    int n = arr.size();
    vector<int> ans(n,n);
    stack<int> s;
    for(int i = n-1 ; i >= 0 ; i--){
      while(!s.empty() && arr[s.top()] >= arr[i]){
        s.pop();
      }
      ans[i] = s.empty() ? n : s.top();
      s.push(i);
    }
    return ans;
}
int largestRectangle(vector < int > & heights) {
    // Write your code here.
    vector<int> pse1 = pse(heights);
    vector<int> nse1 = nse(heights);
    int area = 0;
    for(int i = 0 ; i < heights.size() ; i++){
      int areaCalc = heights[i] * (nse1[i] - pse1[i] - 1);
      area = max(area,areaCalc);
    }
    return area;
 }

 tc = 2 * o(2n) + o(n) = o(5n)
 sc = o(4n)