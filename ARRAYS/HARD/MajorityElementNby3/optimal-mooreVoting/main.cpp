// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         int count1 = 0 ;
//         int element1 = INT_MIN;
//         int count2 = 0 ;
//         int element2 = INT_MIN;
//         int n = nums.size();
//         for(int i = 0 ; i < n ; i++){
//             if(count1 == 0 && nums[i] != element2){
//                 count1 = 1;
//                 element1 = nums[i];
//             }
//             else if(count2 == 0 && nums[i] != element1){
//                 count2 = 1;
//                 element2 = nums[i];
//             }
//             else if (element1 == nums[i]) count1++;
//             else if (element2 == nums[i]) count2++;

//             else{
//                 count1--;
//                 count2--;
//             }
//         }
//         vector <int> ans;
//         int min = (int)(n/3) + 1;
//         count1 = 0 , count2 = 0;
//         for(int i = 0 ; i < n ; i++){
//             if(element1 == nums[i]) count1++;
//             if(element2 == nums[i]) count2++;
//         }
//         if(count1 >= min) ans.push_back(element1);
//         if(count2 >= min) ans.push_back(element2);

//         return ans;
//     }
// };

// tc  = O(2N)
// SC = O(1)