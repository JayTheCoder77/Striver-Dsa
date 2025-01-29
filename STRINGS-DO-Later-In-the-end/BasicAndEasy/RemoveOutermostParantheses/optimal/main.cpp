class Solution {
public:
    string removeOuterParentheses(string s) {
        // optimal counter based approach
        int counter = 0;
        string ans = "";
        for(auto ch : s){
            if(ch == '('){
                if(counter != 0) ans += ch;
                counter++;
            }
            else if(ch == ')'){
                counter--;
                if(counter != 0) ans += ch;
            }
        }
        return ans;
    }
};

tc = o(n)
sc = o(1)