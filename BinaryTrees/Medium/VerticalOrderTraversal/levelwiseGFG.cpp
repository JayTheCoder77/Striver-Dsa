used vector instead of multiset as we require multiple nodes in same level in unsorted -> as they appear in level order traversal

meanwhile in leetcode we needed the multiset to get nodes in sorted order

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        // Your code here
        // level order traversal bfs
        map<int , map<int , vector<int> > > nodes; 
        queue<pair < Node* , pair <int , int > > > todo; // top down
        // node , vertical , level
        todo.push({root , {0 , 0}});
        // bfs
        while(!todo.empty()){
            auto p = todo.front();
            todo.pop();
            Node* node = p.first;
            int x = p.second.first , y = p.second.second;
            nodes[x][y].push_back(node -> data); 
            if(node -> left) todo.push({node -> left , {x -1  , y + 1}});
            if(node -> right) todo.push({node -> right , {x + 1  , y + 1}});
        }
        vector<vector<int>> ans;
        for(auto p : nodes){
            vector<int> col;
            for(auto q : p.second){
                col.insert(col.end() , q.second.begin() , q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};