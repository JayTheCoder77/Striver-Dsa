# recursion backtracking

void generate(vector<string> &result ,string s , int open , int close, int n){
    if(open == n && close == n){
        result.push_back(s);
        return;
    }
    if(open < n){
        generate(result,s + "(",open + 1,close,n);
    }
    if(close < open){
        generate(result,s + ")",open,close + 1,n);
    }
}
vector<string> validParenthesis(int n){
    // Write your code here.
    string s = "";
    int open = 0 , close = 0;
    vector <string> result;
    generate(result,s,open,close,n);
    return result;
}

tc =  O(4^n / √n) catalan number
sc =  O(n) + O(4^n / √n)