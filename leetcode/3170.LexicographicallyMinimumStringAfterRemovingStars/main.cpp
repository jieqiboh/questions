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
    string clearStars(string s) {
        // we have 26 + 1 stacks to store the indexes of each char encountered
        vector<stack<int>> stacks(26);
        set<int> del;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                // find lowest non-empty stack
                for (stack<int>& st : stacks) {
                    if (!st.empty()) {
                        del.insert(st.top());
                        st.pop();
                        break;
                    }
                }
            } else { // is a lowercase char
                stacks[s[i] - 97].push(i);
            }
        }

        // reconstruct the string
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            if (del.find(i) == del.end() && s[i] != '*') {
                res += s[i];
            }
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    string s = "aaba*";
    cout << sol.clearStars(s) << "\n";

    return 0;
}

