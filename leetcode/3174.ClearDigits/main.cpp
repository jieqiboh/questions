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
    string clearDigits(string s) {
        set<int> removed;

        stack<int> st; // contains idxes of numbers
        for (int i = s.size() - 1; i >= 0; i--) {
            if (!isalpha(s[i])) {
                st.push(i);
            } else {
                if (!st.empty()) {
                    int prevNumIdx = st.top();
                    st.pop();
                    removed.insert(i);
                    removed.insert(prevNumIdx);
                }
            }
        }
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            if (removed.find(i) == removed.end()) {
                res += s[i];
            }
        }
        return res;
    }
};

int main() {
    fast();

    return 0;
}

