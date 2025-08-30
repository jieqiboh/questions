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
#define ll long long

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freqMap;
        for (int i = 0; i < word.size(); i++) {
            freqMap[word[i]]++;
        }
        int finalres = INT32_MAX;
        int startRes = 0;
        while (!freqMap.empty()) {
            finalres = min(finalres, compute(freqMap, k, startRes));
        }
        return finalres;
    }

    int compute(unordered_map<char, int>& freqMap, int k, int& startRes) {
        // computes min no of chars deleted to make word special assuming all chars in freqMap used
        int minVal = INT32_MAX;
        for (pair<char, int> p : freqMap) {
            minVal = min(minVal, p.second);
        }

        int res = startRes;
        // freq of all chars must be [minVal, minVal + k]
        for (pair<char, int> p : freqMap) {
            if (p.second > minVal + k) {
                res += p.second - (minVal + k);
            }
        }

        // erase all chars from freqMap where val == minVal
        for (auto it = freqMap.begin(); it != freqMap.end(); ) {
            if (it->second == minVal) {
                startRes += it->second;
                it = freqMap.erase(it);  // erase returns the next valid iterator
            } else {
                ++it;
            }
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    string word = "aabcaba";
    int k = 0;
    cout << sol.minimumDeletions(word, k) << "\n"; // 3

    return 0;
}

