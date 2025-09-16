class DisjointSet {
    vector<int> rank , parent , size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findUParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u , int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u , int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }

        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        unordered_map <string , int> mapMailNode;
        DisjointSet ds(n);

        for(int i = 0 ; i < n ; i++){
            // we start j from 1 as 0 -> name 
            for(int j = 1 ; j < accounts[i].size() ; j++){
                string mail = accounts[i][j];

                // not found in map
                if(mapMailNode.find(mail) == mapMailNode.end()) mapMailNode[mail] = i;

                else{
                    ds.unionBySize(i , mapMailNode[mail]);
                }
            }
        }

        // merge the mails
        vector<vector<string>> mergedMails(n);
        for(auto it : mapMailNode){
            int node = ds.findUParent(it.second);
            string mail = it.first;

            mergedMails[node].push_back(mail);
        }

        // final ans with name and emails

        vector<vector<string>> ans;
        for(int i = 0 ; i < n ; i++){
            if(mergedMails[i].size() == 0) continue;
            sort(mergedMails[i].begin() , mergedMails[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : mergedMails[i]) temp.push_back(it);

            ans.push_back(temp);
        }
        return ans;
    }
};