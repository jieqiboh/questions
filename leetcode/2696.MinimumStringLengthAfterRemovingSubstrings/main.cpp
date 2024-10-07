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
    int minLength(string s) {
        stack<char> st;

        int sz = s.size();
        for (char c : s) {
            if (c == 'D' || c == 'B') {
                if (st.empty()) continue;
                char top = st.top();
                if ((c == 'D' && top == 'C') || (c == 'B' && top == 'A')) {
                    sz -= 2;
                    st.pop();
                } else {
                    st.push(c);
                }
            } else {
                st.push(c);
            }
        }
        return sz;
    }
};

int main() {
    fast();
    Solution sol;
    string s = "ACDB";
    cout << sol.minLength(s) << "\n"; // 0

    s = "ABFCACDB";
    cout << sol.minLength(s) << "\n"; // 2

    s = "ACBBD";
    cout << sol.minLength(s) << "\n"; // 5

    s = "VKBAJBOYY";
    cout << sol.minLength(s); // 9

    return 0;
}

