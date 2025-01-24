class Solution {
public:
    int bs(vector<int>matrix,int target){
        int low = 0;
        int n = matrix.size();
        int high = n - 1;
        while(low <= high){
            int mid = (low + high)/2;
            if(matrix[mid] == target) return mid;
            else if(matrix[mid] > target) high = mid - 1;
            else low = mid + 1; 
        }
        return -1;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        for(int i = 0 ; i < n ; i++){
            int index = bs(matrix[i],target);
            if(index != -1) return true; // return {i , index}
        }
        return false; // return {-1,-1}
    }
};

tc = o(n * log2m)