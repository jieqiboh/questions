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
    int maximumGain(string s, int x, int y) {
        int res = 0;
        if (x > y) {
            s = removeSubstring(s, "ab", res, x);
            removeSubstring(s, "ba", res, y);
        } else {
            s = removeSubstring(s, "ba", res, y);
            removeSubstring(s, "ab", res, x);
        }
        return res;        return res;
    }

    string removeSubstring(const string& input, const string& targetPair, int& res, int pts) {
        stack<char> charStack;

        // Iterate through each character in the input string
        for (char currentChar : input) {
            // Check if current character forms the target pair with the top of
            // the stack
            if (currentChar == targetPair[1] && !charStack.empty() &&
                charStack.top() == targetPair[0]) {
                charStack.pop();  // Remove the matching character from the stack
                res += pts;
            } else {
                charStack.push(currentChar);
            }
        }

        // Reconstruct the remaining string after removing target pairs
        string remainingChars;
        while (!charStack.empty()) {
            remainingChars += charStack.top();
            charStack.pop();
        }
        reverse(remainingChars.begin(), remainingChars.end());
        return remainingChars;
    }
};

int main() {
    fast();
    Solution sol;
    string s = "cdbcbbaaabab";
    cout << sol.maximumGain(s, 4, 5); // 19

    return 0;
}

