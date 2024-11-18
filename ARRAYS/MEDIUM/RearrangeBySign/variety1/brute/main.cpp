// vector<int> alternateNumbers(vector<int>&a) {
//     // Write your code here.
//     int n = a.size();
//     int positive[n/2];
//     int negative[n/2];
//     int a1 = 0 , a2 = 0;
//     for(int i = 0 ; i < n ; i++){
//         if(a[i] < 0){
//             negative[a1++] = a[i];
//         }
//         else{
//             positive[a2++] = a[i];
//         }
//     }

//     for(int i = 0; i < n/2 ; i++){
//         a[2*i] = positive[i];
//         a[2*i + 1] = negative[i];
//     }
//     return a;
// }


//  tc - 0(n) + 0(n/2)
//  sc = o(n)