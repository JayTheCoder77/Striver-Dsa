class Solution {
public:
    int largestRowElement(vector<vector<int>>& mat , int n , int col){
        // returning largest Row Element index
        int largest = INT_MIN;
        int index = -1;
        for(int i = 0 ; i < n ; i++){
            if(mat[i][col] > largest){
                largest = mat[i][col];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0 , high = m - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            int largest_row_element = largestRowElement(mat,n,mid); // index of the largest element in the coresspondiing row
            int left = (mid - 1 >= 0) ? mat[largest_row_element][mid-1] : INT_MIN;
            int right = (mid + 1 < m) ? mat[largest_row_element][mid+1] : INT_MIN;
            if(mat[largest_row_element][mid] > left && mat[largest_row_element][mid] > right) return {largest_row_element,mid};
            else if(mat[largest_row_element][mid] < left) high = mid - 1;
            else low = mid + 1;
        }
        return {-1,-1};
    }
};

tc = o(n * log2m)