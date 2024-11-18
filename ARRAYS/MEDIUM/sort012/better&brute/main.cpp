//brute - use sorting methods

// better - time O(2n)

// #include <bits/stdc++.h> 

// void sortArray(vector<int>& arr, int n)
// {
//     // Write your code here - better solution using count 0 1 2
//     int count0 = 0;
//     int count1 = 0;
//     int count2 = 0;

//     for(int i = 0 ; i < n ; i++){
//         if(arr[i] == 0){
//             count0++;
//         }
//         if(arr[i] == 1){
//             count1++;
//         }
//         if(arr[i] == 2){
//             count2++;
//         }
//     }

//     for(int i = 0 ; i < count0 ; i++){
//         arr[i] = 0;
//     }
//     for(int i = count0 ; i < count0 + count1 ; i++){
//         arr[i] = 1;
//     }
//     for(int i = count0 + count1 ; i < n ; i++){
//         arr[i] = 2;
//     }
// }
