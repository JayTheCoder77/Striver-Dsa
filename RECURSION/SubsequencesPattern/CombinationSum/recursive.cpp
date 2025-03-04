void generateComb(vector<vector<int>> &ans,vector<int> &ds,vector<int> &arr,int b,int ind){
    if(ind == arr.size()){
        if(b == 0){
        ans.push_back(ds);
        }
        return;
    }
    if(arr[ind] <= b){
        ds.push_back(arr[ind]);
        generateComb(ans,ds,arr,b - arr[ind],ind);
        ds.pop_back();
    }
    generateComb(ans,ds,arr,b,ind+1);
    
}
vector<vector<int>> combSum(vector<int> &ARR, int B)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> ds;
    sort(ARR.begin(), ARR.end());
    generateComb(ans,ds,ARR,B,0);
    return ans;
}

tc = o(2^t * k * nlogn)
sc = o(k * x)
x = no of combinations
k = size of combinations
t = target