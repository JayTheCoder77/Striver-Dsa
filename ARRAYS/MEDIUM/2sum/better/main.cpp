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