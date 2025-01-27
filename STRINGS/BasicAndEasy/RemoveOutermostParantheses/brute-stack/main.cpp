string removeOuter(string& s) {
        // code here
        // brute force using stack
        stack <char> storeParantheses;
        string ans = "";
        for(auto ch : s){
            if(ch == '('){
            if(!storeParantheses.empty()){
                ans += ch;
            }
            }
            storeParantheses.push(ch);
            if(ch == ')'){
            storeParantheses.pop();
            if(!storeParantheses.empty()){
                ans += ch;
            }
            }
        }
        return ans;
    }
tc = o(n)
sc = o(n)