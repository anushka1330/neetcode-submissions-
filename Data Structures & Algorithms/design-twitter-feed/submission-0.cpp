class Twitter {
public:
    int time = 0;

    unordered_map<int, vector<pair<int,int>>> tweets; 
    // userId -> {time, tweetId}

    unordered_map<int, unordered_set<int>> followMap;
    // follower -> set of followees

    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>> all;

        followMap[userId].insert(userId); // include self

        for (int uid : followMap[userId]) {
            for (auto &t : tweets[uid]) {
                all.push_back(t);
            }
        }

        sort(all.rbegin(), all.rend()); // latest first

        vector<int> res;
        for (int i = 0; i < min(10, (int)all.size()); i++) {
            res.push_back(all[i].second);
        }

        return res;
    }

    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followMap[followerId].count(followeeId)) {
            followMap[followerId].erase(followeeId);
        }
    }
};