class Solution {
    public:
    int largestRectangleArea(vector<int>& heights) {
                stack<int> s;
                int maxArea = 0;
                for(int i = 0 ; i < heights.size() ; i++){
                    while(!s.empty() && heights[s.top()] > heights[i]){
                        int top1 = s.top();
                        s.pop();
                        int nse = i;
                        int pse = s.empty() ? -1 : s.top();
                        maxArea = max(maxArea , heights[top1] * (nse - pse - 1));
                    }
                    s.push(i);
                }
                while(!s.empty()){
                    int nse = heights.size();
                    int element = s.top();
                    s.pop();
                    int pse = s.empty() ? -1 : s.top();
                    maxArea = max(maxArea , heights[element] * (nse - pse - 1));
                }
                return maxArea;
            }
          int maximalRectangle(vector<vector<char>>& matrix) {
            int n = matrix.size();
            int m = matrix[0].size();
            int maxArea = 0;
        vector<vector<int>> prefixSum(n, vector<int>(m, 0));
        for(int j = 0 ; j < m ; j++){
            int sum = 0;
            for(int i = 0 ; i < n ; i++){
                sum += matrix[i][j] -'0';
                if(matrix[i][j] - '0' == 0) sum = 0;
                prefixSum[i][j] = sum;
            }
        }
        for(int i = 0 ; i < n ; i++){
            maxArea = max(maxArea , largestRectangleArea(prefixSum[i]));
        }
        return maxArea;
        }
    };

    tc = o(m * n) for prefix sum + o(n * 2m)
    sc = o(n * m) + o(n)