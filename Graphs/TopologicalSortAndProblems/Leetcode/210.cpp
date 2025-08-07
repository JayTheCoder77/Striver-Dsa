class Solution {
public:
    // kahns bfs topological sort 
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for(auto& edge : prerequisites){
            int course = edge[0];
            int prerequisite = edge[1];
            adjList[prerequisite].push_back(course);
        }
        // Calculate indegrees
        vector<int> indegree(numCourses, 0);
        for(int i = 0; i < numCourses; i++){
            for(auto neighbor : adjList[i]) {
                indegree[neighbor]++;   
            }
        }
        
        // Start with zero indegree nodes
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> result;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            result.push_back(node);
            
            // Remove node from graph and update indegrees
            for(auto neighbor : adjList[node]){
                indegree[neighbor]--;
                if(indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // Cycle detection: if we couldn't process all courses, there's a cycle
        return result.size() == numCourses ? result : vector<int>();
    }
};