class Solution {
public:
    void reverseRange(string &s,int start , int end){
        while(start < end){
            swap(s[start++],s[end--]);
        }
    }
    string reverseWords(string s) {
// remove trail and lead spaces
        int n = s.size() , i = 0 , j = 0;
        while(j < n){
            while(j < n && s[j] == ' ') j++;
            if(j >= n ) break;
            if(i != 0) s[i++] = ' ';
            while(j < n && s[j] != ' ') s[i++] = s[j++];
        }
        s.resize(i);
  // reverse
        reverseRange(s,0,i-1);
        int start = 0;
        // reverse again
        for(int end = 0 ; end <= i ; end++){
            if(end == i || s[end] == ' '){
                reverseRange(s,start,end-1);
                start = end + 1;
            }
        }
        return s;
    }
};
      remove spaces + reverse + reverse again
tc = o(n) + o(n) + o(n) = o(n)
sc = o(1)