class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int minI = INT_MAX;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[low] <= nums[high]){
                minI = min(minI,nums[low]);
                break;
            }
            if(nums[low] <= nums[mid]){
                minI = min(minI,nums[low]);
                low = mid + 1;
            }
            else if(nums[mid] <= nums[high]){
                minI = min(minI,nums[mid]);
                high = mid - 1;
            }
        }
        return minI;
    }
};

tc = o(logn) base2