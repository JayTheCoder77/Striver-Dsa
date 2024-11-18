// #include<vector>
// #include <map>
// #include <algorithm>

// int getSingleElement(vector<int> &arr){
// 	// Write your code here.
// 	//better - hashing - using map data struc
// 	map<long long ,int>hash;
// 	for(int i = 0 ;i < arr.size() ; i++){
// 		hash[arr[i]]++; 
// 	}
// 	for(auto it : hash){
// 		if(it.second == 1){
// 			return it.first;
// 		}
// 	}
// 	return -1;
// }



// #include<vector>



// int getSingleElement(vector<int> &arr){
// 	// Write your code here.
// 	//better - hashing

// 	int max1 = arr[0];
// 	for(auto c : arr){
// 		max1 = max(max1,c);
// 	}
// 	vector<int>hash (max1+1 , 0);
// 	for(int i = 0 ;i < arr.size() ; i++){
// 		hash[arr[i]]++; 
// 	}
// 	for(int i = 0 ; i < max1+1 ; i++){
// 		if(hash[i] == 1){
// 			return i;
// 		}
// 	}
// 	return -1;
// }
// 	// //brute	
// 	// for(int i = 0 ; i < arr.size() ; i++){
// 	// 	int count = 0;
// 	// 	int num = arr[i];
// 	// 	for(int j = 0 ; j < arr.size() ; j++){
// 	// 		if(arr[j] == num){
// 	// 			count++;
// 	// 		}
// 	// 	}
// 	// if(count == 1){
// 	// 	return num;
// 	// }
// 	// }