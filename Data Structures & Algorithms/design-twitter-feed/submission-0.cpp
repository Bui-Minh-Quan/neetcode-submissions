class Twitter {
private:
    map<int, set<int>> user_followees;
    map<int, vector<pair<int, int>>> user_posts;
    int time;
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        user_posts[userId].push_back({time, tweetId});
        ++time;
    }
    
    vector<int> getNewsFeed(int userId) {
        set<int> followees = user_followees[userId];
        followees.insert(userId); // user should see their own tweets
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans;
        for (const auto& f:followees) {
            vector<pair<int, int>> temp = user_posts[f];
            int n = temp.size();
            for (int i = max(0, n - 11); i < n; i++)
                pq.push({temp[i].first, temp[i].second});
            
            while (pq.size() > 10)
                pq.pop();
        }

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
    
    void follow(int followerId, int followeeId) {
        user_followees[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        user_followees[followerId].erase(followeeId);
    }
};





