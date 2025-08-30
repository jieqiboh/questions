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
    int minimumLength(string s) {
        unordered_map<char,int> m;

        for (char c : s) {
            m[c]++;
        }

        int count = 0;
        for (pair<char,int> p : m) {
            if (p.second % 2 == 1) {
                count += 1;
            } else {
                count += 2;
            }
        }
        return count;
    }
};

int main() {
    fast();
    Solution sol;
    string s = "aa";
    cout << sol.minimumLength(s) << "\n"; // 2

    s = "abaacbcbb";
    cout << sol.minimumLength(s) << "\n"; // 5
    return 0;
}

