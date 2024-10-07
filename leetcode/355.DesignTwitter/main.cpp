#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <bitset>
#include <utility>
#include <numeric>

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

//struct Compare {
//    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
//        a.
//    }
//};

class Twitter {
private:
    int time;
    unordered_map<int,vector<pair<int,int>>> tweets; // userId, time, tweetID
    unordered_map<int,unordered_set<int>> followees; // maps users to people they are following
public:
    Twitter() {
        this->time = 0;
    }

    void postTweet(int userId, int tweetId) {
        if (this->tweets.find(userId) == tweets.end()) {
            this->tweets[userId] = {};
        }
        this->tweets[userId].push_back({this->time, tweetId});
        this->time++;
    }

    vector<int> getNewsFeed(int userId) {
        // for all the people that userId is following and themself
        // get the 10 latest tweets
        priority_queue<pair<int,int>> lastTweets; // maxheap ordered by 1st
        vector<pair<int,int>> ownTweets = tweets[userId];
        for (int i = 0; i < 10; i++) {
            int idx = ownTweets.size() - 1 - i;
            if (idx >= 0) lastTweets.push(ownTweets[ownTweets.size() - 1 - i]);
        }

        for (int user : followees[userId]) {
            vector<pair<int,int>> userTweets = tweets[user];
            for (int i = 0; i < 10; i++) {
                int idx = userTweets.size() - 1 - i;
                if (idx >= 0) lastTweets.push(userTweets[userTweets.size() - 1 - i]);
            }
        }
        this->time++;
        vector<int> res;
        for (int i = 0; i < 10 && !lastTweets.empty(); i++) {
            res.push_back(lastTweets.top().second);
            lastTweets.pop();
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        this->followees[followerId].insert(followeeId);
        this->time++;
    }

    void unfollow(int followerId, int followeeId) {
        this->followees[followerId].erase(followeeId);
        this->time++;
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

int main() {
    fast();

    // ["Twitter","postTweet","getNewsFeed","follow","postTweet","getNewsFeed","unfollow","getNewsFeed"]
    // [[],[1,5],[1],[1,2],[2,6],[1],[1,2],[1]]

    Twitter* obj = new Twitter();
    obj->postTweet(1,5);
    vector<int> param_2 = obj->getNewsFeed(1);
    obj->follow(1,2);
    obj->postTweet(2,6);
    vector<int> param_3 = obj->getNewsFeed(1);
    obj->unfollow(1,2);
    vector<int> param_4 = obj->getNewsFeed(1);
    return 0;
}

