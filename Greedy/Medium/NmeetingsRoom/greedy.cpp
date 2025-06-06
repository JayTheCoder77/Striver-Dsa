#include<bits/stdc++.h>
struct data{
    int start;
    int end;
    int pos;
};
bool comp(struct data m1 , data m2){
    if (m1.end < m2.end) return true;
         else if (m1.end > m2.end) return false;
         else if (m1.pos < m2.pos) return true;
         return false;
}
int maximumMeetings(vector<int> &start, vector<int> &end)
{
    // Write your code here.
    int n = start.size();
    if(n == 0) return 0;
    vector<data> arr(n);
    for(int i = 0 ; i < n ; i++){
        arr[i].start = start[i];
        arr[i].end = end[i];
        arr[i].pos = i + 1;
    }
    sort(arr.begin(), arr.end(), comp);
    int cnt = 1 , freeTime = arr[0].end;
    for(int i = 1 ; i < n ; i++){
        if(arr[i].start > freeTime){
            cnt++;
            freeTime = arr[i].end;
        }
    }
    return cnt;
}

tc = o(2n + nlogn)
sc = o(3n) + o(n)