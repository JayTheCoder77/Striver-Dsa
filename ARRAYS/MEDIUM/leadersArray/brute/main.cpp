// vector<int> superiorElements(vector<int>&a) {
//     // Write your code here - brute
//     int n = a.size();
//     vector <int> ans (0);
//     for(int i = 0 ; i < n ; i++){
//         bool leader = true;
//         for(int j = i+1 ; j < n ; j++){
//           if (a[j] > a[i]) {
//             leader = false;
//             break;
//           }
//         }
//         if (leader == true && std::find(ans.begin(), ans.end(), a[i]) == ans.end()) {
//             ans.push_back(a[i]);
//         }
//     }
//     std::sort(ans.begin() , ans.end());
//     return ans;
// }