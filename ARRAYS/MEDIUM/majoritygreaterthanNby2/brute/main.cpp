// int majorityElement(vector<int> v) {
// 	// Write your code here - brute
// 	int n = v.size();
// 	int majorFactor = n/2;

// 	for(int i = 0 ; i < n ; i++){
// 		int count = 0;
// 		for(int j = 0 ; j < n ; j++){
// 			if(v[j] == v[i]){
// 				count++;
// 			}
// 		}
// 		if(count > majorFactor) return v[i];
// 	}
    // return -1;
// }