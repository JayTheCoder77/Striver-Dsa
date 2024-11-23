class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = i + 1;
        while(j < n){                         // can also use for loop for(j = 1 ; j < n ; j++)
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
            j++;
        }
        return i+1;
    }
};

tc o(n)
sc = o(1)