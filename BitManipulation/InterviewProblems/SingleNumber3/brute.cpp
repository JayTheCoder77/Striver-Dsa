class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        map<long long int,long long int> mpp;
        vector<long long int> ans;
        for(int i = 0 ; i < N ; i++){
            mpp[Arr[i]]++;
        }
        for(auto it : mpp){
            if((it.second) % 2 == 1) ans.push_back(it.first);
        }
        return ans;
    }
};

m = (n/2) + 1
tc = o(nlogm) + o(m) 
sc = o(m)