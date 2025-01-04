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
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefSum;
        int cnt = 0;
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for (string w : words) {
            if (vowels.find(w[0]) != vowels.end() && vowels.find(w[w.size() - 1]) != vowels.end()) {
                cnt++;
            }
            prefSum.push_back(cnt);
        }

        vector<int> res;

        for (vector<int> q : queries) {
            int lhs = (q[0] > 0) ? prefSum[q[0] - 1] : 0;
            int rhs = prefSum[q[1]];
            res.push_back(rhs - lhs);
        }
        return res;
    }
};

int main() {
    fast();

    return 0;
}

