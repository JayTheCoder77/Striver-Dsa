int binary(vector<int> &nums,int low,int high,int target){
    if (low > high) return -1;
    int mid = (low + high) / 2;
    if(nums[mid] == target) return mid;
    else if(target > nums[mid]) return binary(nums,mid+1,high,target);
    else return binary(nums,low,mid-1,target);

}
int search(vector<int> &nums, int target) {
    // Write your code here.
    return binary(nums,0,nums.size() - 1,target);
}

tc = o(logn)
sc = o(1)
