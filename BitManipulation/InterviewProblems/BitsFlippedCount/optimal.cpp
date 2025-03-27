class Solution {
    public:
        int minBitFlips(int start, int goal) {
            int ans = start ^ goal;
            return __builtin_popcount(ans);
            // or 
            // for (int i = 0 ; i < 31 ; i++){
            //     if(ans & (1 << i)) cnt++;
            // }
        }
    };