class Solution {
    public:
    
    // modification of pse for handling duplicates to psee 
    // (smaller and equal)
    vector<int> previousSmallerEqualElement(vector<int> &arr, int n)
    {
        // Write your code here.
        stack<int> s;
        vector<int> psee(n , -1);
        for(int i = 0 ; i < n; i++){
            while(!s.empty() && arr[i] <= arr[s.top()]){
                s.pop();
            }
            psee[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        return psee;
    }
    vector<int> nextSmallerElement(vector<int> &arr, int n)
    { 
        // Write your code here.
        stack<int> s;
        vector<int> nse(n , n);
        for(int i = n-1 ; i >= 0; i--){
            while(!s.empty() && arr[i] < arr[s.top()]){
                s.pop();
            }
            nse[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        return nse;
    }
     
        int sumSubarrayMins(vector<int>& arr) {
            int n = arr.size();
        int mod = (int)(1e9 + 7);
        vector<int> nse = nextSmallerElement(arr, n);
        vector<int> psee = previousSmallerEqualElement(arr, n);
        
        long long total = 0;
        for(int i = 0; i < n; i++) {
            long long left = i - psee[i];
            long long right = nse[i] - i;
            long long contribution = (left * right % mod) * arr[i] % mod;
            total = (total + contribution) % mod;
        }
        return total;
        }
    };

    tc = o(5n)
    sc = o(5n) nse pse 