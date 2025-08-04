class Solution {
public:
    unordered_map <string , int> mpp;
    vector<vector<string>> ans;
    string b;
    void dfs(string word , vector<string>& seq){
        if(word == b) {
            reverse(seq.begin() ,seq.end());
            ans.push_back(seq);
            reverse(seq.begin() ,seq.end());
            return;
        }
        int steps = mpp[word];
        for(int i = 0 ; i < word.size() ; i++){
            char original = word[i];
            for(char ch = 'a' ; ch <= 'z' ; ch++){
                 word[i] = ch;
                 if(mpp.find(word) != mpp.end() && mpp[word] + 1 == steps){
                    seq.push_back(word);
                    dfs(word , seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set <string> word(wordList.begin() , wordList.end());
        queue<string> q;
        q.push(beginWord);
        word.erase(beginWord);
        mpp[beginWord] = 1;
        b = beginWord;
        int sz = beginWord.size();
        while(!q.empty()){
            string w = q.front();
            int steps = mpp[w];
            q.pop();
            if(w == endWord) break;
            for(int i = 0 ; i < sz ; i++){
                char original = w[i];
                for(char ch = 'a' ; ch <= 'z' ; ch++){
                    w[i] = ch;
                    if(word.count(w)){
                        q.push(w);
                        word.erase(w);
                        mpp[w] = steps + 1;
                    }
                }
                w[i] = original;
            }
        }
        if(mpp.find(endWord) != mpp.end()) {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord , seq);
        }
        return ans;
    }
};