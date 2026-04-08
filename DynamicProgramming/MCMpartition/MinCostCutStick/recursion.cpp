class Solution {
public:
    int f(int i , int j , vector<int> &cuts){
        if(i > j) return 0;
        int mini = INT_MAX;
        for(int ind = i ; ind <= j ; ind++){
            int cost = cuts[j+1] - cuts[i-1] + f(i ,ind-1,cuts) + f(ind+1 , j ,cuts);
            mini = min(mini , cost);
        }
        return mini;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        int size = cuts.size();
        return f(1 , size-2 , cuts);
    }
};