class Twitter {
public:
    unordered_map <int , unordered_set<int>> followMap;
    // userid =>  {time , tweetId}
    unordered_map <int , vector<pair<int,int>>> tweetMap;
    int time;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({time++ , tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> minHeap;
        vector<int> res;
        followMap[userId].insert(userId);
        // followeeId in followMap
        for(int fid : followMap[userId]){
            auto& t = tweetMap[fid];
            for(int i = (int)t.size() - 1 ; i >= 0 && i >= (int)t.size() - 10 ; i--){
                minHeap.push({t[i]});
                if (minHeap.size() > 10)
                    minHeap.pop();
            }
        }
        while (!minHeap.empty()) {
            res.push_back(minHeap.top().second); // tweetId
            minHeap.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId && followMap.find(followerId) != followMap.end())
            followMap[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */