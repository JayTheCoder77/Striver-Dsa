class Solution {
  public:
    vector<int> maxCombinations(int n, int k, vector<int> &a, vector<int> &b) {
        // code here
        vector<int> ans;
        priority_queue <pair<int , pair<int,int>>> maxHeap;
        set <pair<int,int>> index; 
        sort(a.begin() , a.end());
        sort(b.begin() , b.end());
        maxHeap.push({a.back() + b.back() , {n-1 , n-1}});
        index.insert({n-1,n-1});
        while(k--){
            auto p = maxHeap.top();
            int sum = p.first;
            int i = p.second.first;
            int j = p.second.second;
            ans.push_back(sum);
            maxHeap.pop();
            
            if(index.find({i-1 , j}) == index.end()){
                maxHeap.push({a[i-1] + b[j] , {i-1 , j}});
                index.insert({i-1 , j});
            }
            if(index.find({i , j-1}) == index.end()){
                maxHeap.push({a[i] + b[j-1] , {i , j-1}});
                index.insert({i , j-1});
            }
        }
        return ans;
    }
};

tc = o(nlogn) + (k log k)
sc = o(k + nlogn)