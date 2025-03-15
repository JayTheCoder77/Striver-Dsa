void generate(int i ,int k , int sum , int n , 
    vector<vector<int>> &ans, vector<int> &ds){
        if(k < 0) return;
        if(sum == n){
            if(k == 0){
                ans.push_back(ds);
            }
            return;
        }
        if(i == 10) return;
        // pick
        sum += i;
        ds.push_back(i);
        k -= 1;
        generate(i+1,k,sum,n,ans,ds);
        // backtrack
        k += 1;
        sum -= i;
        ds.pop_back();
    
        // not pick
        generate(i+1,k,sum,n,ans,ds);
    }
    vector<vector<int>> combinationSum(int k, int n) {
        // Write Your Code Here
        vector<vector<int>> ans;
        vector<int> ds;
        generate(1,k,0,n,ans,ds);
        return ans;
    }

    tc = o(9 ^ k)
    sc = o(k) + o(9 ^ k * k)