// more optimizations from better
// flatten 2d matriix into 1d hypothetically

bool searchMatrix(vector<vector<int>>& mat, int target) {
    int m = mat[0].size();
    int n = mat.size();
    int low = 0;
    int high = (n * m) - 1;
    while (low <= high) {
      int mid = (low + high) / 2;
      int row = mid / m;
      int col = mid % m;

      if (mat[row][col] == target)
        return true;
      else if (mat[row][col] > target)
        high = mid - 1;
      else
        low = mid + 1;
    }
    return false;
}

tc = o(log2 (n x m))