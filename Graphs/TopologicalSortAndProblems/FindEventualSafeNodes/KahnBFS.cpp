class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> adjRev (V);
        vector<int> indegree (V , 0);
        for(int i = 0 ; i < V ; i++){
            // i -> it
            // we want to reverse edges ie - it -> i
            for(auto it : graph[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        vector<int> safeNodes;
        for(int i = 0 ; i < V ; i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        // bfs kahn
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for(auto it : adjRev[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        sort(safeNodes.begin() , safeNodes.end());
        return safeNodes;
    }
};

We wish to find a set of eventual safe nodes in the original graph G. 
Let T be the set of terminal nodes of G. A node 'p' in G is eventual safe if it's neither part of a cycle nor it can 'reach' any cycle. 
In other words, all the 'outgoing' paths from 'p' can only reach one of the terminal nodes T. 
Conversely, if 'q' is an unsafe node, then there exists at least one 'outgoing' path which leads to a cycle (or unsafe nodes). 
Now when we reverse G, in the reversed graph, all the outgoing paths become incoming paths and vice-versa. 
Let's call the reversed graph H. Note that the 'terminal' nodes T of G becomes the start nodes for the topological sort on H.

In the reversed graph H, all the 'incoming' paths to 'p' must start from some terminal node in T (and must contain no cycles). 
On the other hand, there exists at least one 'incoming' path to 'q' which originates from some unsafe node (connected to a cycle). 
Now when we perform Kahn's topological sort starting from the terminal nodes T, and repeatedly remove edges from terminal node set to its neighbors,
at some point, all 'incoming' edges to 'p' will be removed and its indegree will become 0, 
and hence 'p' will be collected as a safe node. On the other hand, 'q' will be left with at least one edge (involving unsafe nodes connected to a cycle), 
and hence its indegree would never become zero, and hence it will not be collected as a safe node.

In Kahn’s Algorithm for topological sorting, we actually remove nodes that have no incoming edges


