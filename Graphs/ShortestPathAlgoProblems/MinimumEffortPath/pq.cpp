class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // store diff , {row , col}
        int n = heights.size() , m = heights[0].size();
        // min heap
        priority_queue <pair<int , pair<int,int>>  , vector<pair<int , pair<int,int>>> , greater<pair<int , pair<int,int>>> > pq;

        vector<vector<int>> diff (n , vector<int> (m , 1e9));
        diff[0][0] = 0;
        pq.push({0 , {0,0}});
        int delRow[] = {-1, 0 , 1 , 0};
        int delCol[] = {0 , 1 , 0 , -1};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int dif = it.first;
            int row = it.second.first , col = it.second.second;

            if(row == n-1 && col == m-1) return dif;

            for(int i = 0 ; i < 4 ; i++){
                int newR = row + delRow[i] , newC = col + delCol[i];
                if(newR >= 0 && newR < n && newC >= 0 && newC < m){
                    int newEffort = max( abs(heights[row][col] - heights[newR][newC]) , dif);
                    if(newEffort < diff[newR][newC]){
                        diff[newR][newC] = newEffort;
                        pq.push({newEffort , {newR ,newC}});
                    }
                }
            }
        }
        return 0;
    }
};

tc = o(4nm x logv)
sc = o(nm)