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
    string simplifyPath(string path) {
        stack<char> s;
        s.push(path[0]);
        string res;
        int dot_count = 0; // represents the number of dots in the stack

        for (int i = 1; i < path.size(); i++) {
            char c = path[i];
            char top = s.top();

            if (c == '/') {
                if (top == '/') { // ?//
                    s.pop();
                    s.push(c);
                } else if (top == '.') { // ./
                    if (dot_count == 1) { // ?../
                       dot_count--;


                    } else if (dot_count == 2) {

                    } else {

                    }
                }
            } else if (c == '.') {
                if (top != '.') {
                    res += s.top();
                    s.pop();
                }
                s.push(c);
                dot_count++;
            } else {
                if (top == '/') {
                    res += s.top();
                    s.pop();
                    s.push(c);
                } else if (top == '.') {
                    if (dot)

                } else {

                }
            }
        }

    }
};

int main() {
    fast();

    Solution sol;
    string path = "/home/";
    cout << sol.simplifyPath(path) << "\n"; // "/home"

    path = "/home//foo/";
    cout << sol.simplifyPath(path) << "\n"; // "/home/foo"

    path = "/home/user/Documents/../Pictures";
    cout << sol.simplifyPath(path) << "\n"; // "/home/user/Pictures"

    path = "/";
    cout << sol.simplifyPath(path) << "\n"; // "/"
    return 0;
}

