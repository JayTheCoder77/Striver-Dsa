

class Solution {
  public:
    // Function to return the minimum cost to react at bottom
    // right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        
        vector<vector<int>> dist(n , vector<int> (m , 1e9));
        
        // min heap
        priority_queue <
            pair<int, pair<int,int>>, 
            vector<pair<int, pair<int,int>>>, 
            greater<pair<int, pair<int,int>>>
        > pq;
        
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});

        int dx[] = {-1 , 0 , 1 , 0 };
        int dy[] = {0 , 1 , 0 , -1 };
        
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            
            int cost = top.first;
            int x = top.second.first;
            int y = top.second.second;
            
            // Reached destination
            if(x == n-1 && y == n-1) 
                return cost;
            
            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                
                if(nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    int newCost = cost + grid[nx][ny];
                    
                    if(newCost < dist[nx][ny]) {
                        dist[nx][ny] = newCost;
                        pq.push({newCost, {nx, ny}});
                    }
                }
            }
        }
        return dist[n-1][n-1];
    }
};