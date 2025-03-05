class Solution {
    public:
        bool isAcronym(vector<string>& words, string s) {
            string result = "";
            for(auto i : words){
                result += i[0];
            }
            if(result == s) return true;
            return false;
        }
    };

    leetcode 2828 Check if a String Is an Acronym of Words