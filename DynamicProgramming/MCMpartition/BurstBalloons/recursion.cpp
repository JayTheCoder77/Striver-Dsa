class Solution {
public:
    int f(int i , int j , vector<int>& nums){
        if(i > j) return 0;
        int maxi = INT_MIN;
        for(int ind = i ; ind <= j ; ind++){
            int cost = nums[i-1] * nums[ind] * nums[j + 1] + f(i , ind - 1 , nums) + f(ind + 1 , j , nums);
            maxi = max(maxi , cost);
        }
        return maxi;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin() , 1);
        nums.push_back(1);
        return f(1 , nums.size() - 2 , nums);
    }
};