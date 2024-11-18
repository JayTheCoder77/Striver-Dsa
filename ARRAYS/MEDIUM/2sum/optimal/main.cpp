// #include<bits/stdc++.h>
// string read(int n, vector<int> book, int target)
// {
//     //better - hashing

//     map<int , int> hash;

//     for(int i = 0;i<n;i++){
//         int a = book[i];
//         int more = target - a;
//         if(hash.find(more) != hash.end()){
//           return "YES"; // return {hash[more] , i};
//         }
//         hash[a] = i;
//     }
//     return "NO";
// }


// this is better for returning yes or no but optimal for returning index 









//now optimal for returning yes or no

//  int left = 0;
//     int right = n -1;
//     sort(book.begin() , book.end());
//     while (left < right) {
//       int sum = book[left] + book[right];
//       if (sum == target) return "YES";
//       else if(sum < target) left++;
//       else right--;

//     }
//     return "NO";