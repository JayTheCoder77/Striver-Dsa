COURSE SCHEDULE - SAME AS FIND CYCLE IN AN UNDIRECTED GRAPH

returns true if all courses can be finished (i.e., no cycle)
if cycle exists return false 

class Solution {
private:
    bool dfs(int node , vector<vector<int>> &graph , int vis[] , int pathVis[]){
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto e : graph[node]){
            // if not visited
            if(!vis[e]){
                if(dfs(e , graph , vis , pathVis)) return true;
            }
            else if(pathVis[e]){
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }
public:
    // detect cycle in directed graph
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // create adj list
        vector<vector<int>> graph(numCourses);
        int vis [numCourses];
        int pathVis [numCourses];
        for(int i = 0 ; i < numCourses ; i++){
            vis[i] = 0;
            pathVis[i] = 0;
        }
        for (auto prerequisite : prerequisites) {
            int u = prerequisite[1];
            int v = prerequisite[0];
            graph[u].push_back(v);
        }
        // connected components case


        // if dfs returns true it means cycle exists
        for(int i = 0 ; i < numCourses ; i++){
            if(!vis[i]){
                if(dfs(i , graph , vis , pathVis)) return false;
            }
        }
        return true;
    }
};