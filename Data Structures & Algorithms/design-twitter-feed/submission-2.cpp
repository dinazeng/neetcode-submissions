class Twitter {
public:
    struct myComp {
        bool operator()(const vector<int>& s1, const vector<int> & s2) {
            // For a MIN-HEAP (lowest score at the top), use '>'
            // If s1.score is greater than s2.score, s1 yields priority to s2
            return s1[2] < s2[2]; 
        }
    };

    priority_queue<vector<int>, vector<vector<int>>, myComp> myFeed;
    unordered_map<int, set<int>> myFollowing;
    int tweetNumber = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        myFeed.push({userId, tweetId, tweetNumber});
        myFollowing[userId].insert(userId);    
        tweetNumber++;    
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue <vector<int>, vector<vector<int>>, myComp> myCopyFeed = myFeed;
        vector<int> tweets;
        while (tweets.size() < 10 && !myCopyFeed.empty()) {
            if (myFollowing[userId].contains(myCopyFeed.top()[0])) {
                tweets.push_back(myCopyFeed.top()[1]);
            }

            myCopyFeed.pop();
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
