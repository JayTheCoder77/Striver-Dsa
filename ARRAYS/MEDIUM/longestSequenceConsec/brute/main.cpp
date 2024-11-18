// bool ls(vector<int> arr , int num , int n){
//     for(int i = 0 ; i < n ; i++){
//         if(arr[i] == num) return true;
//     }
//     return false;
// }


// int longestSuccessiveElements(vector<int>&a) {
//     // Write your code here.
//     int longest = 1;
//     int n = a.size();

//     for(int i = 0 ; i < n ; i++){
//         int x = a[i];
//         int count = 1;

//         while(ls(a , x + 1 , n) == true){
//             x += 1;
//             count++;
//         }
//     longest = max(longest, count);
//     }
//     return longest;
// }