class Solution{
	public:
	bool checkPrime(int n){
	    int count = 0 ;
	    for(int i = 1 ; i <= sqrt(n) ; i++){
	        if(n % i == 0){
	            count++;
	            if(n/i != i){
	                count++;
	            }
	        }
	        if(count > 2) break;
	    }
	    if(count == 2) return true;
	    return false;
	}
	vector<int>AllPrimeFactors(int N) {
	    // Code here
	    vector<int> ans;
	    for(int i = 2; i <= N ; i++){
	        if(N % i == 0){
	            if(checkPrime(i)) ans.push_back(i);
	        }
	    }
	    return ans;
	}
};

tc = o(sqrt(n) * n)
sc = o() we cant predict as we use sc to return ans