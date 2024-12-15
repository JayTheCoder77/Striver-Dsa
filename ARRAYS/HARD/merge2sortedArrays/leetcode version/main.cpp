class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m - 1;
        int right = 0;
        while(left >= 0 && right < n){
            if(nums1[left] > nums2[right]){
                swap(nums1[left],nums2[right]);
                left--;
                right++;
            }
            else{
                break;
            }
        }
        sort(nums2.begin(),nums2.end());
        int i = m;
        for (int num : nums2) {
            nums1[i++] = num;
        }
        sort(nums1.begin(), nums1.begin() + m + n);
    }
};