leetcode 8 directional - 1091

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        pair<int , int > source {0 , 0};
        pair<int , int > destination {n - 1  , n - 1};
        if(grid[source.first][source.second] == 1) return -1;
        if(source == destination) return 1;
        vector<vector<int>> dist(n , vector<int> (m , 1e9));
        
        
        // no need of priority queue for djikstras algo in this case
        queue <pair <int , pair <int , int >> > q;
        // distance , node coordinates
        q.push({1 , {source.first , source.second}});
        dist[source.first][source.second] = 0;
        
        int delRow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int delCol[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            for(int i = 0 ; i < 8 ; i++){
                int newR = r + delRow[i];
                int newC = c + delCol[i];
                

                if(newR >= 0 && newR < n && newC >= 0 && newC < m && grid[newR][newC] == 0 && dis + 1 < dist[newR][newC]){
                    if(destination.first == newR && destination.second == newC) return dis + 1;
                    dist[newR][newC] = dis + 1;
                    q.push({dis + 1, {newR , newC}});
                }
            }
        }
        return -1;
    }
};