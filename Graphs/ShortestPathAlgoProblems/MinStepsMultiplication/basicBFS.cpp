class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // basic bfs
        queue<int> q;
        int mod = 1e5;
        vector<int> vis (mod , 0);
        q.push(start);
        vis[start] = 1;
        
        int cnt = 0;
        while(!q.empty()){
            cnt++;
            int n = q.size();
            for(int i = 0 ; i < n ; i++){
                int node = q.front();
                q.pop();
                if(node == end) return cnt - 1;
                for(auto i : arr){
                    int num = (i * node) % mod;
                    if(!vis[num]){
                        vis[num] = 1;
                        q.push(num);
                    }
                }
            }
        }
        return -1;
    }
};