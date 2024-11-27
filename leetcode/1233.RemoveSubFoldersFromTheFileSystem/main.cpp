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
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());

        vector<string> res;
        res.push_back(folder[0]);
        string prev = folder[0];
        for (int i = 1; i < folder.size(); i++) {
            string cur = folder[i];
            if (cur.substr(0, prev.size()) != prev) {
                res.push_back(cur);
                prev = cur;
                continue;
            }

            if (cur.size() > prev.size() && cur[prev.size()] != '/') {
                res.push_back(cur);
                prev = cur;
                continue;
            }
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<string> folder = {"/a","/a/b","/c/d","/c/d/e","/c/f"};
    vector<string> res = sol.removeSubfolders(folder);
    for (string s : res) {
        cout << s << " ";
    }
    cout << "\n";

    return 0;
}

