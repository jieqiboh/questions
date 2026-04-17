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
using ll = long long;

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> curPath;
        stringstream ss(path);
        string token;

        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
            } else if (token == "..") {
                if (!curPath.empty()) curPath.pop_back();
            } else {
                curPath.push_back(token);
            }
        }

        string res = "";
        for (auto& s : curPath) res += "/" + s;
        return res.empty() ? "/" : res;
    }
};

int main() {
    fast();
    Solution sol;
    string path = "/..//_home/a/b/..///";
    cout << sol.simplifyPath(path) << "\n";
    path = "/..//";
    cout << sol.simplifyPath(path) << "\n";
    path = "/neetcode/practice//...///../courses";
    cout << sol.simplifyPath(path) << "\n";
    path="/..hidden";
    cout << sol.simplifyPath(path) << "\n"; // /..hidden

    return 0;
}

