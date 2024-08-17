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

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        // strings are close if character freq are equal, and contain the same set of distinct chars
        unordered_set<char> chars1;
        unordered_set<char> chars2;
        for (char c : word1) {
            chars1.insert(c);
        }
        for (char c : word2) {
            chars2.insert(c);
        }
        if (chars1 != chars2) return false; // sets should be identical

        unordered_map<char, int> map_w1; // map of char freq of word1
        unordered_map<char, int> map_w2; // map of char freq of word2
        for (char c : word1) {
            map_w1[c]++;
        }
        for (char c : word2) {
            map_w2[c]++;
        }
        vector<int> v1;
        for (auto& x : map_w1) {
            v1.push_back(x.second);
        }
        vector<int> v2;
        for (auto& x : map_w2) {
            v2.push_back(x.second);
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        return v1 == v2;
    }
};

int main() {
    fast();
    Solution sol;
    string word1 = "abcdd";
    string word2 = "abbcd";
    cout << sol.closeStrings(word2, word1) << "\n"; // 1

    word1 = "abcde";
    word2 = "abbcd";
    cout << sol.closeStrings(word2, word1) << "\n"; // 0
    return 0;
}

