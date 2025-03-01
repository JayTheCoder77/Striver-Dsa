leetcode Solution
recursion

class Solution {
    public:
        void generate(vector<string> &result,int n, string s){
            if(s.length() == n){
                result.push_back(s);
                return;
            }
            generate(result,n,s + '1');
    
            if(s.empty() || s.back() == '1') generate(result,n,s + '0'); 
        }
        vector<string> validStrings(int n) {
            vector <string> result;
            generate(result,n,"");
            return result;
        }
    };

    tc = o(2^n)
    sc = O(n x F(n+2))
    F = fibonacci num