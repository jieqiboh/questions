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

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

struct Compare {
    bool operator()(pair<char, int>& a, pair<char, int>& b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // Init pq
        priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> pq; // maps char to their current frequency
        if (a > 0) pq.push({'a', a});
        if (b > 0) pq.push({'b', b});
        if (c > 0) pq.push({'c', c});

        string res = "";
        while (!pq.empty()) {
            pair<char, int> cur = pq.top();
            pq.pop();
            char c = cur.first;

            if (res.size() >= 2 && res[res.size() - 1] == c && res[res.size() - 2] == c) { // if both prev chars are the same as cur char
                if (pq.empty()) break; // no more chars to consider, end loop
                pair<char, int> next = pq.top();
                pq.pop();
                res += next.first;
                if (next.second - 1 > 0) pq.push({next.first, next.second - 1});
                pq.push({cur.first, cur.second});
            } else {
               res += cur.first;
               if (cur.second - 1 > 0) pq.push({cur.first, cur.second - 1});
            }
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    cout << sol.longestDiverseString(1,1,7) << "\n"; // ccaccbcc
    cout << sol.longestDiverseString(1,1,0) << "\n"; // ab
    cout << sol.longestDiverseString(1,0,0) << "\n"; // ab
    cout << sol.longestDiverseString(7,1,0) << "\n"; // aabaa


    return 0;
}

