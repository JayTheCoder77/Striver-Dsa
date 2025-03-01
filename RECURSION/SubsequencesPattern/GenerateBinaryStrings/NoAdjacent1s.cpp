gfg Solution
recursion

class Solution{
    public:
        void generate(int n , string s, vector<string> &result){
            if(s.length() == n){
                result.push_back(s);
                return;
            }
            generate(n,s + '0' , result);
            if(s.empty() || s.back() == '0') generate(n,s + '1',result);
        }
        vector<string> generateBinaryStrings(int num){
            //Write your code
            vector<string> result;
            generate(num ,"",result);
            return result;
        }
    };

    tc = o(2^n)
    sc = O(n x F(n+2))
    F = fibonacci num
