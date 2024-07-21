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

using namespace std;

#define uset unordered_set
#define umap unordered_map
#define endl '\n'

typedef vector<int> vi;
typedef long long ll;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (int i = 0; i < tokens.size(); i++) {
            string c = tokens[i];
            if (c == "+") {
                int first = s.top();
                s.pop();
                int second = s.top();
                s.pop();
                s.push(first + second);
            } else if (c == "-") {
                int first = s.top();
                s.pop();
                int second = s.top();
                s.pop();
                s.push( second - first);
            } else if (c == "*") {
                int first = s.top();
                s.pop();
                int second = s.top();
                s.pop();
                s.push(first * second);
            } else if (c == "/") {
                int first = s.top();
                s.pop();
                int second = s.top();
                s.pop();
                s.push(second / first);
            } else { // number
                s.push(stoi(c));
            }
        }
        return s.top();
    }
};

int main() {
    fast();

    Solution sol;
    vector<string> tokens = {"2","1","+","3","*"};
    cout << sol.evalRPN(tokens) << "\n";

    return 0;
}

