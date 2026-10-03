class Twitter {
public:
    map<int, vector<int>> myFeed;
    unordered_map<int, unordered_set<int>> myFollowing;
    int tweetNumber = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        myFeed[tweetNumber] = {userId, tweetId};
        myFollowing[userId].insert(userId);    
        tweetNumber++;    
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> tweets;
        auto it = myFeed.rbegin();
        while (tweets.size() < 10 && it != myFeed.rend()) {
            if (myFollowing[userId].contains(it->second[0])) {
                tweets.push_back(it->second[1]);
            }

            it++;
        }

        return tweets;
    }
    
    void follow(int followerId, int followeeId) {
        myFollowing[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        myFollowing[followerId].erase(followeeId);
    }
};
