brute force naive sol
with two maps one for follow list and other for tweets
class Twitter {
public:
    unordered_map<int , unordered_set<int>> followees;
    unordered_map<int , vector<pair<int,int>>> tweets;
    int timeStamp = 0;
    // Implement the below functions.
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++ , tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>> all;
        followees[userId].insert(userId); // follow self for access
        for(int f : followees[userId]) all.insert(all.end() , tweets[f].begin() , tweets[f].end());
        sort(all.rbegin(), all.rend());
        vector<int> res;
        for(int i = 0 ; i < all.size() ; i++) res.push_back({all[i].second});
        return res;
    }

    void follow(int followerId, int followeeId) {
        followees[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
    }
};

tc = o(f * t log(f * t))
sc = o(f * t)