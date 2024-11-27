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
    bool eval(char op, vector<int>& v) {
        bool res = v[0];
        if (op == '&') {
            for (int i = 1; i < v.size(); i++) {
                res &= v[i];
            }
        } else if (op == '|') {
            for (int i = 1; i < v.size(); i++) {
                res |= v[i];
            }
        } else { // op == '!'
            return !res;
        }
        return res;
    }

    bool parseBoolExpr(string expression) {
        stack<char> st;
        vector<int> v;

        for (char c : expression) {
            if (c == ')') {
                while (st.top() != '(') {
                    if (st.top() != ',') {
                        if (st.top() == 'f') {
                            v.push_back(0);
                        } else {
                            v.push_back(1);
                        }
                    }
                    st.pop();
                }
                st.pop();
                char op = st.top();
                st.pop();
                bool res = eval(op, v);
                v.clear();
                st.push(res == 1 ? 't' : 'f');
            } else {
                st.push(c);
            }
        }
        return st.top() == 't' ? 1 : 0;
    }
};

int main() {
    fast();
    Solution sol;
    string expression = "&(|(f))";
    cout << sol.parseBoolExpr(expression) << "\n"; // false

    expression = "|(f,f,f,t)";
    cout << sol.parseBoolExpr(expression) << "\n"; // true

    expression = "!(&(f,t))";
    cout << sol.parseBoolExpr(expression) << "\n"; // true

    return 0;
}

