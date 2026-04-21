class Solution {
public:
    // histogram problem + dp
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
    int maximalRectangle(vector<vector<char>>& mat) {
        int maxArea = 0;
        int n = mat.size();
        int m = mat[0].size();
        vector<int> height(m, 0);
        for(int i = 0; i< n; i++) {
            for(int j = 0; j<m; j++) {
                if(mat[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            int area = largestRectangleArea(height);
            maxArea = max(area, maxArea) ;
        }
        return maxArea;
    }
};