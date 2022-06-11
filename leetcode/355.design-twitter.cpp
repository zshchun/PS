class Twitter {
    deque<pair<int,int>> tweets;
    unordered_map<short,bool> *follows;
public:
    Twitter() {
    	follows = new unordered_map<short,bool>[501];
    }
    
    void postTweet(int userId, int tweetId) {
	    tweets.emplace_back(make_pair(tweetId, userId));
	    if (tweets.size() > 5000) {
		    tweets.pop_front();
	    }
    }
    
    vector<int> getNewsFeed(int userId) {
	    int cnt = 10;
	    vector<int> recentTweets;
	    auto it = tweets.rbegin();
	    while (cnt > 0 && it != tweets.rend()) {
		    int tweetUserId = it->second;
		    if (userId == tweetUserId || follows[userId][tweetUserId]) {
			    recentTweets.push_back(it->first);
			    cnt--;
		    }
		    it++;
	    }
	    return recentTweets;
    }
    
    void follow(int followerId, int followeeId) {
	    follows[followerId][followeeId] = true;
        
    }
    
    void unfollow(int followerId, int followeeId) {
	    follows[followerId][followeeId] = false;
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
