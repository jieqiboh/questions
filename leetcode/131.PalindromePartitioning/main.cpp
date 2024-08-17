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
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> tempList;
        backtrack(res, tempList, s, 0);
        return res;
    }
    void backtrack(vector<vector<string>>& res, vector<string>& tempList, const string& s, int start) {
        if (start > s.size() - 1) {
            res.push_back(tempList);
        } else {
            for (int i = start; i < s.size(); i++) {
                string str = s.substr(start, i - start + 1);
                if (!isPalindrome(str)) continue;
                tempList.push_back(str);
                backtrack(res, tempList, s, i + 1);
                tempList.pop_back();
            }
        }
    }
    bool isPalindrome(string s) {
        int r = s.size() - 1;
        int l = 0;
        while (l <= r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};

int main() {
    fast();
    Solution sol;
    string s = "aab";
    vector<vector<string>> res = sol.partition(s);
    for (vector<string> v : res) {
        for (string s : v) {
            cout << s << " ";
        }
        cout << "\n";
    }


    return 0;
}

