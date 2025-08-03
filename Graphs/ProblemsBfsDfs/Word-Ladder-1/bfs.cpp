class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // bfs
        queue <pair < string , int > > q;
        // set - works like visited array
        unordered_set <string> vis (wordList.begin() , wordList.end());
        q.push({beginWord , 1});
        vis.erase(beginWord);

        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == endWord) return steps;
            // traverse word char by char
            for(int i = 0 ; i < word.size() ; i++){
                char original = word[i];
                for(char j = 'a' ; j <= 'z' ; j++){
                    word[i] = j;
                    if(vis.find(word) != vis.end()){
                        q.push({word , steps + 1});
                        vis.erase(word);
                    }
                    word[i] = original;
                } 
            }
        }
        return 0;
    }
};

tc = o(n * word.len * 26 * logn (set))
sc = o(n)