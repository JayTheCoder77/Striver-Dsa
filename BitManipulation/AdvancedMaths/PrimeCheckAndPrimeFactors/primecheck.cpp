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

    tc = o(sqrt(n))
    sc = o(1)