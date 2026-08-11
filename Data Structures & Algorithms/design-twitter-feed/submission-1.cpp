class Twitter {
private:
    using Tweet = pair<int, int>; // {time, tweetId}

    unordered_map<int, unordered_set<int>> followees;
    unordered_map<int, vector<Tweet>> tweets;

    int timestamp = 0;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        // {time, userId, index of tweet}
        using Node = tuple<int, int, int>;

        priority_queue<Node> pq;

        // User should see their own tweets.
        followees[userId].insert(userId);

        // Put each user's latest tweet into the heap.
        for (int followee : followees[userId]) {
            if (!tweets[followee].empty()) {
                int i = tweets[followee].size() - 1;

                pq.push({
                    tweets[followee][i].first,
                    followee,
                    i
                });
            }
        }

        vector<int> feed;

        while (!pq.empty() && feed.size() < 10) {
            auto [time, user, index] = pq.top();
            pq.pop();

            feed.push_back(tweets[user][index].second);

            // Add this user's next newest tweet.
            if (index > 0) {
                --index;

                pq.push({
                    tweets[user][index].first,
                    user,
                    index
                });
            }
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {
        followees[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
    }
};