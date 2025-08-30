class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int n = arr.size();
        int mod = 1e5;
        //  node , steps
        queue<pair<int,int>> q;
        vector<int> dist(mod , 1e9);
        q.push({start , 0});
        dist[start] = 0;
        while(!q.empty()){
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            if (start == end) return 0;

            for(auto i : arr){
                int num = (i * node) % mod;
                if(steps + 1 < dist[num]){
                    dist[num] = steps + 1;
                    if(num == end) return steps + 1;
                    q.push({num , steps + 1});
                }
            }
        }
        return -1;
    }
};