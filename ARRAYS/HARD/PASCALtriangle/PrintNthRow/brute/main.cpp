// int nCr (int n , int r){
//     int res = 1;
//     for (int i = 0; i < r; i++)
//     {
//         res = res * (n - i);
//         res = res / (i + 1);
//     }
//     return res;
// }

// void getRow (int n){
//     for (int c = 1; c <= n; c++)
//     {
//         cout << nCr(n-1 , c-1) << " ";
//     }
// }