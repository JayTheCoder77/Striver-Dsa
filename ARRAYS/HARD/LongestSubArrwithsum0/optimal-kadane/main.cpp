 class Solution {
   public:
     int maxLen(vector<int>& arr) {
         // code here - kadane
         int n = arr.size();
         int preSum = 0;
         int maxI = 0;
         map <int,int> hash;
         for(int i = 0 ; i < n ; i++){
             preSum += arr[i];
            if(preSum == 0){
                 maxI = i + 1;
             }
             else{
                 if(hash.find(preSum) != hash.end()){
                     maxI = std::max(maxI , i - hash[preSum]);
                 }
                 else{
                     hash[preSum] = i;
                 }
             }
         }
         return maxI;
     }
 };

 tc = o (nlogn)
 sc = o(n)