int countSubstring(string s){
    // Write your code here.
        int count = 0;
        for(int i = 0 ; i < s.length() ; i++){
            int hash[3] = {0};
            for(int j = i ; j < s.length() ; j++){
                hash[s[j] - 'a'] = 1;
                if(hash[0] + hash[1] + hash[2] == 3) count++;
            }
        }
        return count;
}

tc = o(n2)
sc = o(3)



better 

int countSubstring(string s) {
    // Code here
    int n = s.length();
    int count = 0;
    for(int i = 0 ; i < s.length() ; i++){
        int hash[3] = {0};
        for(int j = i ; j < s.length() ; j++){
        hash[s[j] - 'a'] = 1;
        if(hash[0] + hash[1] + hash[2] == 3){
            count = count + (n - j);
            break;
        }
    }
}
return count;
}