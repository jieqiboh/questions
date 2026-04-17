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
using ll = long long;

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // find first idx of every occurrence of every word in words
        // maintain a visited set of used words
        // then from each first idx, do a sort of dfs?

        int wordSize = words[0].size();
        int windowSize = wordSize * words.size();
        if (windowSize > s.size()) {
            return {};
        }
        unordered_map<string,int> freqMap;
        for (string& w : words) {
            freqMap[w]++;
        }

        vector<int> res;

        for (int i = 0; i <= s.size() - windowSize; i++) {
            // check if this substring contains a valid perm
            unordered_map<string, int> tmp = freqMap;
            bool valid = true;
            for (int k = 0; k < windowSize; k += wordSize) {
                string w = s.substr(k + i, wordSize);
                if (tmp.find(w) != tmp.end()) {
                    tmp[w]--;
                    if (tmp[w] == 0) tmp.erase(w);
                } else {
                    valid = false;
                    break;
                }
                // cout << w;
                // cout << " ";
            }
            if (!valid || !tmp.empty()) {
                continue;
            }
            res.push_back(i);
            // cout << "\n";
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    string s = "barfoothefoobarman";
    vector<string> words = {"foo","bar"};
    vector<int> res = sol.findSubstring(s, words); // 0 9
    for (int x : res) {
        cout << x << " ";
    }
    cout << "\n";

    s = "wordgoodgoodgoodbestword";
    words = {"word","good","best","word"};
    res = sol.findSubstring(s, words); // empty
    for (int x : res) {
        cout << x << " ";
    }
    cout << "\n";

    s = "barfoofoobarthefoobarman";
    words = {"bar","foo","the"};
    res = sol.findSubstring(s, words); // 6 9 12
    for (int x : res) {
        cout << x << " ";
    }
    cout << "\n";

    s = "wordgoodgoodgoodbestword";
    words = {"word","good","best","good"};
    res = sol.findSubstring(s, words); // 8
    for (int x : res) {
        cout << x << " ";
    }
    cout << "\n";

    s = "a";
    words = {"a","a"};
    res = sol.findSubstring(s, words); // empty
    for (int x : res) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}

