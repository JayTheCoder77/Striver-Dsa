class Solution {
public:
    int minI(vector<int>&bloomDay){
        int mini = INT_MAX;
        for(int i = 0 ; i < bloomDay.size() ; i++){
            mini = min(mini,bloomDay[i]);
        }
        return mini;
    }
    int maxI(vector<int>&bloomDay){
        int maxi = INT_MIN;
        for(int i = 0 ; i < bloomDay.size() ; i++){
            maxi = max(maxi,bloomDay[i]);
        }
        return maxi;
    }
    bool findBoq(vector <int> &bloomDay,int boq,int m,int k){
        int n = bloomDay.size();
        int count = 0 , total = 0;
        for(int i = 0 ; i < n ; i++){
            if(bloomDay[i] <= boq){
                count++;
            }
            else{
                total += count/k;
                count = 0;
            }
        }
        total += count / k;
        if(total >= m) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = minI(bloomDay);
        int high = maxI(bloomDay);
        int n = bloomDay.size();
        if((long long)m * k >(long long) n) return -1;
        while(low <= high){
            int mid = (low + high) /2;
            if(findBoq(bloomDay,mid,m,k) == true) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};
Tc = o( n x log2 (high-low+1))