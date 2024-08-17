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
    int compress(vector<char>& chars) {
        string s = "";
        char curChar = chars[0];
        int curLen = 1;
        for (int i = 1; i < chars.size(); i++) {
            if (chars[i] != curChar) {
                if (curLen > 1) {
                    string charLen = to_string(curLen);
                    s += curChar + charLen;
                } else {
                    s += curChar;
                }
                curChar = chars[i];
                curLen = 1;
            } else {
                curLen++;
            }
        }
        if (curLen > 1) {
            string charLen = to_string(curLen);
            s += curChar + charLen;
        } else {
            s += curChar;
        }
        for (int i = 0; i < s.length(); i++) {
            chars[i] = s[i];
        }
        return s.length();
    }
};

int main() {
    fast();

    Solution sol;
    vector<char> chars = {'a','a','b','b','c','c','c'};
    sol.compress(chars);
    for (auto& c : chars) {
        cout << c << " ";
    }
    cout << "\n";

    chars = {'a'};
    sol.compress(chars);
    for (auto& c : chars) {
        cout << c << " ";
    }
    cout << "\n";

    chars = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    sol.compress(chars);
    for (auto& c : chars) {
        cout << c << " ";
    }
    cout << "\n";
    return 0;
}

