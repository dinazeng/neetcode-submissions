class Twitter {
public:
    priority_queue<pair<int, pair<int, int>>> feeds_all;
    unordered_map<int, set<int>> follows;
    int tweet_count;

    Twitter() {
        tweet_count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        feeds_all.push({tweet_count++, {userId, tweetId}});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, pair<int, int>>> temp = feeds_all;

        vector<int> feed;
        auto& followed = follows[userId];
        int found = 0;

        while (!temp.empty() && found < 10) {
            int author = temp.top().second.first;
            int tweetId = temp.top().second.second;
            temp.pop();

            if (author == userId || followed.count(author)) {
                feed.push_back(tweetId);
                found++;
            }
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};
