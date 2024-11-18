// vector<int> alternateNumbers(vector<int>&a) {
//     // Write your code here.
//     vector <int> pos , neg;
//     int n = a.size();
//     for(int i = 0 ; i < n ; i++){
//         if(a[i] < 0) neg.push_back(a[i]);
//         else pos.push_back(a[i]);
//     }
//     if(pos.size() > neg.size()){
//         for(int i = 0 ; i < neg.size() ; i++){
//             a[2*i] = pos[i];
//             a[2*i+1] = neg[i];
//         }
//         int index = neg.size() * 2;
//         for(int j = neg.size() ; j < pos.size() ;j++){
//             a[index] = pos[j];
//             index++;
//         }
//     }
//     else{
//          for(int i = 0 ; i < pos.size() ; i++){
//             a[2*i] = pos[i];
//             a[2*i+1] = neg[i];
//         }
//         int index = pos.size() * 2;
//         for(int j = pos.size() ; j < neg.size() ;j++){
//             a[index] = neg[j];
//             index++;
//         }
//     }
//     return a;
// }