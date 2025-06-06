class Twitter {
public:
    std::unordered_map<int,std::unordered_set<int>> f_map;
    std::unordered_map<int,vector<pair<int,int>>> t_map;
    int time;
    // std::stack<pair<int,int>> st;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        t_map[userId].push_back({time,tweetId});
        time++;        
    }
    
    vector<int> getNewsFeed(int userId) {
        std::priority_queue<pair<int, int>, std::vector<pair<int, int>>, std::greater<pair<int, int>>> pq; // Min heap
        std::vector<int> res;
        int k = 0;
        for (const auto& tweet : t_map[userId]) {
            pq.push(tweet); // Push tweet with timestamp
            if (pq.size() > 10) pq.pop(); // Ensure heap size is capped at 10
        }

        // Add tweets of the users that the current user is following
        for (int f : f_map[userId]) {
            for (const auto& tweet : t_map[f]) {
                pq.push(tweet); // Push tweet with timestamp
                if (pq.size() > 10) pq.pop(); // Ensure heap size is capped at 10
            }
        }
        while (!pq.empty() && res.size() <10){
            res.push_back(pq.top().second);
            pq.pop();
        }  
        std::reverse(res.begin(), res.end());      
        return res;
    }

    void follow(int followerId, int followeeId) {
        f_map[followerId].insert(followeeId);        
    }
    
    void unfollow(int followerId, int followeeId) {
        f_map[followerId].erase(followeeId);        
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