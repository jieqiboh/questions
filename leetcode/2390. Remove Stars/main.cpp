#include "string"
#include <deque>
#include <iostream>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        deque<char> res;
        for (char c : s) {
            if (c != '*') {
                res.push_front(c);
            } else {
                res.pop_front();
            }
        }
        string result;
        while (!res.empty()) {
            result += res.back();
            res.pop_back();
        }
        return result;
    }
};

int main() {
    auto sol = Solution();
    string s = "leet**cod*e";
    cout << sol.removeStars(s);
    return 0;
}