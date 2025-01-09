class Solution {
public:
    int time(vector<int> &piles,int hourly){
        int n = piles.size();
        long long rate = 0;
        for(int i = 0 ; i < n ; i++){
            rate += (long long)(piles[i] + hourly - 1) / hourly;
        }
        if(rate > INT_MAX) return INT_MAX;
        return rate;
    }
    int findmax(vector<int> &piles){
        int n = piles.size();
        int maxI = INT_MIN;
        for(int i = 0 ;i < n ;i++){
            maxI = max(maxI,piles[i]);
        }
        return maxI;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findmax(piles);
        while(low <= high){
            int mid = (low + high) / 2;
            int totalHours = time(piles,mid);
            if(totalHours <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};

tc = o(n) to find max + o(n log(m))
where m is max num of bananas