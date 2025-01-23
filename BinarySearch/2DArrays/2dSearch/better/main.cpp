// optimal binary search in 2d matrix

bool bs(vector<int>arr,int target){
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if(arr[mid] == target) return true;
      else if(target > arr[mid]) low = mid + 1;
      else high = mid - 1;
    }
    return false;
}
bool searchMatrix(vector<vector<int>>& mat, int target) {
    int m = mat[0].size();
    int n = mat.size();
    for(int i = 0 ; i < n ; i++){
    if(mat[i][0] <= target && target <= mat[i][m-1]){
        return bs(mat[i],target);
    }
}
return false;
}


tc = o(n) + o(log2m)
