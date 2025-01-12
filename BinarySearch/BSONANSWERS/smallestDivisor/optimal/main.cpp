class Solution {
public:
    int maxi(vector<int>&nums){
        int maxI = INT_MIN;
        for(int i = 0 ; i < nums.size() ; i++){
            maxI = max(maxI,nums[i]);
        }
        return maxI;
    }
    int divide(vector<int>&nums,int d){
        // d = divisor
        int total = 0;
        for(int i = 0 ; i < nums.size(); i++){
            total += ceil((double)nums[i]/d);
        }
        return total;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        if(n > threshold) return -1;
        int low = 1;
        int high = maxi(nums);
        while(low <= high){
            int mid = (low + high) / 2;
            int ans = divide(nums,mid);
            if(ans <= threshold) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};

tc = o(n) for max  + o(n * log2maxI) another n for dividing in arr