class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        if(grid[source.first][source.second] == 0) return -1;
        if(source == destination) return 0;
        int n = grid.size() , m = grid[0].size();
        vector<vector<int>> dist(n , vector<int> (m , 1e9));
        
        
        // no need of priority queue for djikstras algo in this case
        queue <pair <int , pair <int , int >> > q;
        // distance , node coordinates
        q.push({0 , {source.first , source.second}});
        dist[source.first][source.second] = 0;
        
        int delRow[] = {-1 , 0 , 1 , 0 };
        int delCol[] = {0 , 1 , 0 , -1 };
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            for(int i = 0 ; i < 4 ; i++){
                int newR = r + delRow[i];
                int newC = c + delCol[i];
                

                if(newR >= 0 && newR < n && newC >= 0 && newC < m && grid[newR][newC] == 1 && dis + 1 < dist[newR][newC]){
                    if(destination.first == newR && destination.second == newC) return dis + 1;
                    dist[newR][newC] = dis + 1;
                    q.push({dis + 1, {newR , newC}});
                }
            }
        }
        return -1;
    }
};