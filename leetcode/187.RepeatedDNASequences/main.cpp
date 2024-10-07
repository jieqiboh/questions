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
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> substrings; // existing substrings of length 10
        set<string> res;

        string cur = s.substr(0, 10);
        substrings.insert(cur);
        if (s.size() <= 10) return {};

        int i = 0;
        int j = 10; // idx of new char to consider
        while (j < s.size()) {
            cur += s[j];
            cur = cur.substr(1, 10);
            if (substrings.find(cur) != substrings.end()) {
                res.insert(cur);
            }
            substrings.insert(cur);
            j++;
        }
        return vector<string>(res.begin(), res.end());
    }
};

int main() {
    fast();
    Solution sol;
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> res = sol.findRepeatedDnaSequences(s);
    for (string s : res) {
        cout << s << " ";
    }

    return 0;
}

