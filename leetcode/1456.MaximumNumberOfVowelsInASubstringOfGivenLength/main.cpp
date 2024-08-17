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
    int maxVowels(string s, int k) {
        unordered_set<char> v({'a','e','i','o','u'});

        int max_vow = 0;
        int cur_vow = 0; // no of vowels in the cur substring
        for (int i = 0; i < k; i++) {
            if (v.find(s[i]) != v.end()) {
                cur_vow++;
            }
        }
        max_vow = max(max_vow, cur_vow);

        int i = 0;
        int j = k - 1;
        while (j < s.size()) {
            if (v.find(s[i]) != v.end()) cur_vow--; // lost a vowel
            j++;
            if (j < s.size() && v.find(s[j]) != v.end()) cur_vow++;
            i++;
            max_vow = max(max_vow, cur_vow);
        }

        return max_vow;
    }
};

int main() {
    fast();
    Solution sol;
    string s = "abciiidef";
    int k = 3;
    cout << sol.maxVowels(s, k) << "\n"; // 3

    s = "f";
    k = 1;
    cout << sol.maxVowels(s, k) << "\n"; // 0

    s = "fbo";
    k = 1;
    cout << sol.maxVowels(s, k) << "\n"; // 1

    s = "abicupo";
    k = 7;
    cout << sol.maxVowels(s, k) << "\n"; // 4

    return 0;
}

