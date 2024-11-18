// #include <bits/stdc++.h>
// vector<int> majorityElement(vector<int> v) {
//   // better using hashing
//   map<int, int> mpp;
//   vector <int> ans;
//   int n = v.size();
//   int min = (int)(n/3) + 1;
//   for(int i = 0 ; i < n ;i++){	 
// 		  mpp[v[i]]++;
// 		  if( mpp[v[i]] == min){
// 			  ans.push_back(v[i]);
// 		  }
//       if(ans.size() ==2 ) break;
//   }
//   sort(ans.begin(),ans.end());
----------------------------------
// //   for(auto it : mpp){                     === this extra iteration can be avoided
// // 	  if(it.second > n/3)
// // 	  ans.push_back(it.first);
// //   }
---------------------------------
//   return ans;
// }

// // tc - 0(n * log n)
// // or 
// // tc = O(n * 1)

// // sc = O(n)