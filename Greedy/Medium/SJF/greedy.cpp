class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        sort(bt.begin() , bt.end());
        long long t = 0 , wt = 0;
        for(int i = 0 ; i < bt.size() ; i++){
            wt += t;
            t += bt[i];
        }
        return wt / bt.size();
    }
};

tc = o(nlogn) + o(n)
sc = o(1)