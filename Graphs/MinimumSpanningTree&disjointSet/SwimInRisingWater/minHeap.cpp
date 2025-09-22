class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        // min heap -> elevation , x , y
        priority_queue <pair<int , pair<int , int>> , vector<pair<int , pair<int , int>>> , greater<pair<int , pair<int , int>>>> pq;
        vector<vector<int>> vis(n , vector<int> (n , 0));
        pq.push({grid[0][0] , {0 , 0}});
        vis[0][0] = 1;
        
        int delRow[] = {-1 , 0 , 1, 0};
        int delCol[] = {0 , 1 , 0 , -1};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int elevation = it.first; // elevation = t
            int r = it.second.first;
            int c = it.second.second;

            // return if last cell
            if(r == n -1 && c == n - 1) return elevation;

            for(int i = 0 ; i < 4 ; i++){
                int newr = r + delRow[i];
                int newc = c + delCol[i];

                if(newr >= 0 && newr < n && newc >= 0 && newc < n && !vis[newr][newc]){
                    vis[newr][newc] = 1;
                    pq.push({ max(elevation , grid[newr][newc]) , {newr , newc}});
                }
            }
        }
        return -1;
    }
};