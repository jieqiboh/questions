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
    int partitionString(string s) {
        if (s.size() == 1) return 1;
        int count = 0;
        unordered_set<char> contains; // contains chars in the current window

        for (int i = 0; i < s.size(); i++) {
            if (contains.find(s[i]) != contains.end()) {
                count++;
                contains.clear();
                contains.insert(s[i]);
            } else {
                contains.insert(s[i]);
            }
        }
        return count + 1;
    }
};

int main() {
    fast();
    Solution sol;
    string s = "abacaba";
    cout << sol.partitionString(s) << "\n"; // 4

    s = "aaa";
    cout << sol.partitionString(s) << "\n"; // 3

    s = "a";
    cout << sol.partitionString(s) << "\n"; // 1
    return 0;
}

