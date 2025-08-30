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

void solve() {
    string s; cin >> s;

    stack<char> st;
    int i = 0;
    for (; i < s.size(); i++) {
        char cur = s[i];

        if (st.empty()) {
            st.push(cur);
        } else {
            if (st.top() == cur) { // pair encountered
                st.pop();
                if (i < s.size() - 1) { // a next char exists
                    st.push(s[i + 1]);
                } else if (!st.empty()) { // a prev char exists
                    st.push(st.top());
                }
            } else {
                st.push(cur);
            }
        }
    }
    cout << st.size() << "\n";
}

int main() {
    fast();
    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

