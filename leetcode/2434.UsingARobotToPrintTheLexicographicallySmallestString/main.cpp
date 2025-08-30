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
    string robotWithString(string s) {
        stack<char> st;
        vector<char> minChar(s.size());
        char smallest = s[s.size() - 1];
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] < smallest) smallest = s[i];
            minChar[i] = smallest;
        }

        string res = "";

        for (int i = 0; i < s.size(); i++) {
            char mChar = minChar[i];

            if (st.empty()) {
                st.push(s[i]);
            } else if (st.top() <= mChar) {
                res.push_back(st.top());
                st.pop();
                i--;
            } else {
                st.push(s[i]);
            }
        }
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    string s = "bdazb";
    cout << sol.robotWithString(s) << "\n"; // abzdb

    s = "zza";
    cout << sol.robotWithString(s) << "\n"; // azz

    s = "bac";
    cout << sol.robotWithString(s) << "\n"; // abc

    s = "bdda";
    cout << sol.robotWithString(s) << "\n"; // addb
    return 0;
}

