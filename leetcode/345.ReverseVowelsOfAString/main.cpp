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
    string reverseVowels(string s) {
        if (s.size() == 1) return s;
        int l = 0;
        int r = s.length() - 1;

        unordered_set<char> v({'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'});
        while (l < r) {
            // find first instance of vowel from start and end of string
            while (v.find(s[l]) == v.end() && l < r) {
                l++;
            }
            while (v.find(s[r]) == v.end() && l < r) {
                r--;
            }
            char tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            l++;
            r--;
        }
        return s;
    }
};

int main() {
    fast();
    Solution sol;
    string s = "hello";
    sol.reverseVowels(s);

    return 0;
}

