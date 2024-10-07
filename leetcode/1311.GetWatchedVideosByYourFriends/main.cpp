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

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        unordered_map<int,vector<int>> fmap; // maps idx to list of friends
        unordered_map<int,vector<string>> vmap; // maps idx to list of videos watched
        map<string,int> resmap; // maps
        for (int i = 0; i < friends.size(); i++) {
            fmap[i] = friends[i];
        }
        for (int i = 0; i < watchedVideos.size(); i++) {
            vmap[i] = watchedVideos[i];
        }

        vector<bool> visited(fmap.size());
        queue<int> q;
        q.push(id);
        visited[id] = true;
        for (int i = 0; i < level; i++) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                int cur = q.front();
                q.pop();
                for (int frnd : fmap[cur]) {
                    if (!visited[frnd]) {
                        visited[frnd] = true;
                        q.push(frnd);
                    }
                }
            }
        }
        while (!q.empty()) { // for each frnd in q, add their freq to resmap
            int cur = q.front();
            for (string vid : vmap[cur]) {
                resmap[vid]++;
            }
            q.pop();
        }
        // Create a vector of pairs to store map elements
        vector<pair<string,int>> vec(resmap.begin(), resmap.end());

        // Custom comparator for sorting: first by int, then by char
        sort(vec.begin(), vec.end(), [](const std::pair<string, int>& a, const std::pair<string, int>& b) {
            if (a.second == b.second) {
                return a.first < b.first; // Sort by char if int is the same
            }
            return a.second < b.second; // Sort by int first
        });

        vector<string> res;
        for (int i = 0; i < vec.size(); i++) {
            res.push_back(vec[i].first);
        }

        return res;
    }
};

int main() {
    fast();
    vector<vector<string>> watchedVideos = {{"A","B"},{"C"},{"B","C"},{"D"}};
    vector<vector<int>> friends = {{1,2},{0,3},{0,3},{1,2}};
    int id = 0;
    int level = 1;
    Solution sol;
    vector<string> res = sol.watchedVideosByFriends(watchedVideos, friends, id, level);
    for (string s : res) {
        cout << s << " ";
    }
    cout << "\n";

    return 0;
}

