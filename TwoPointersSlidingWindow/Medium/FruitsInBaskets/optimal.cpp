class Solution {
    public:
        int totalFruit(vector<int>& fruits) {
            int maxLen = 0;
            int l = 0 , r = 0;
            map<int,int> mpp; // num , freq
            while(r < fruits.size()){
                mpp[fruits[r]]++;
                if(mpp.size() > 2){
                    mpp[fruits[l]]--;
                    if(mpp[fruits[l]] == 0) mpp.erase(fruits[l]);
                    l++;
                }
                if(mpp.size() <= 2) maxLen = max(maxLen , r - l + 1);
                r++;
            }
            return maxLen;
        }
    };

    tc = o(n)
    sc = o(3)