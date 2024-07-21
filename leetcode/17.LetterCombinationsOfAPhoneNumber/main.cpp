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

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        unordered_map<char, vector<char>> map; // maps chars to their lists
        map['2'] = {'a','b','c'};
        map['3'] = {'d','e','f'};
        map['4'] = {'g','h','i'};
        map['5'] = {'j','k','l'};
        map['6'] = {'m','n','o'};
        map['7'] = {'p','q','r','s'};
        map['8'] = {'t','u','v'};
        map['9'] = {'w','x','y','z'};

        queue<string> q;
        q.push("");
        for (int i = 0; i < digits.size(); i++) {
            char c = digits[i];
            while (q.front().size() == i) { // 0, 1, 2, ...
                string cur = q.front();
                for (char x : map[c]) {
                    q.push(cur + x);
                }
                q.pop();
            }
        }
        vector<string> res;
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};

int main() {
    fast();

    Solution sol;
    string digits = "23";
    vector<string> res = sol.letterCombinations(digits);

    for (auto& s : res) {
        cout << s << " ";
    }
    cout << "\n";

    return 0;
}

