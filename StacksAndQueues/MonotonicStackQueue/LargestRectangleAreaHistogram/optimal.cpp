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
    };

    tc = o(n) + o(n) = o(2n)
    sc = o(n)