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

#define uset unordered_set
#define umap unordered_map
#define endl '\n'

typedef vector<int> vi;
typedef long long ll;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> ci; // maps chars to their current counts

        if (s.size() != t.size()) return false;

        for (int i = 0; i < s.size(); i++) {
            ci[s[i]]++; // inc val of each char by 1
        }

        for (int i = 0; i < s.size(); i++) {
            ci[t[i]]--; // dec val of each char by 1
        }

        for (auto& x : ci) {
            if (x.second != 0) return false;
        }
        return true;
    }
};

int main() {
    fast();

    Solution sol;
    string s = "anagram";
    string t = "nagaram";
    cout << sol.isAnagram(s,t) << "\n"; // 1

    s = "rat";
    t = "car";
    cout << sol.isAnagram(s,t) << "\n"; // 0

    return 0;
}

