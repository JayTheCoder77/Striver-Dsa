// vector<int> majorityElement(vector<int> v) {
// 	// Write your code here
// 	vector <int> ansList;
// 	int n = v.size();
// 	for(int i = 0;i < n ; i++){
// 		if(ansList.size() == 0 || ansList[0] != v[i]){
// 				  int count = 0;
//                   for (int j = 0; j < n; j++) {
// 					  if(v[j] == v[i]) count++;
//                   }
// 				if(count > n/3) ansList.push_back(v[i]);
//                 }
// 				if(ansList.size() == 2) break;
//         }
// 	return ansList;
// }