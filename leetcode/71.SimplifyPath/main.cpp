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

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string cur = "";

        for (char c : path + "/") {
            if (c == '/') {
                if (cur == "..") {
                    if (!s.empty()) s.pop();
                } else if (cur != "" && cur != ".") {
                    s.push(cur);
                }
                cur = "";
            } else {
                cur += c;
            }
        }
        string res = "";
        while (!s.empty()) {
            res = ("/" + s.top()) + res;
            s.pop();
        }
        return (res == "") ? "/" : res;
    }
};

int main() {
    fast();
    Solution sol;
    string path = "/home/";
    cout << sol.simplifyPath(path) << "\n";


    path = "/home//foo/";
    cout << sol.simplifyPath(path) << "\n"; // "/home/foo"

    path = "/home/user/Documents/../Pictures";
    cout << sol.simplifyPath(path) << "\n"; // "/home/user/Pictures"

    return 0;
}

