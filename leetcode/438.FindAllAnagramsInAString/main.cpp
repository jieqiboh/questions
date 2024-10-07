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
    bool isSameMap(unordered_map<char,int> smap, unordered_map<char,int> pmap) {
        for (pair<char,int> s : smap) {
            if (pmap[s.first] != s.second) return false;
        }
        return smap.size() == pmap.size();
    }
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) return {}; // not possible to form anagrams
        unordered_map<char, int> smap; // contains freq of chars [l, r]
        unordered_map<char, int> pmap; // contains freq of chars in p
        int l = 0;
        for (char c : p) pmap[c]++;

        vector<int> res;
        // [l,r] cover range of chars the size of p
        for (int i = 0; i < p.size(); i++) smap[s[i]]++;
        if (isSameMap(smap, pmap)) res.push_back(l);

        // at the start of every loop, r is the new char to consider
        for (int r = p.size(); r < s.size(); r++) {
            smap[s[l]]--;
            l++;
            smap[s[r]]++;
            if (isSameMap(smap, pmap)) res.push_back(l);
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    string s = "cbaebabacb"; // 0, 6, 7
    string p = "abc";
    vector<int> res = sol.findAnagrams(s, p);
    for (int i : res) {
        cout << i << " ";
    }

    return 0;
}

