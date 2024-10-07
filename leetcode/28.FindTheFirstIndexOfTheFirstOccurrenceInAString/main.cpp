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

typedef vector<int> vi;
typedef long long ll;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    int strStr(string haystack, string needle) {
        // KMP Algorithm
        // The usual naive method takes O(nm) time
        // Longest Prefix Suffix Array
        // Observation:
        vector<int> lps = prefix_function(haystack);
        int n = haystack.size();
        int m = needle.size();
        if (m > n) return -1;
        if (m == n) return (haystack == needle) ? 0 : -1;
        if (haystack == "") return -1;

        int i = 0;
        int j = 0;
        while (i < n && j < m) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            } else if (j > 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
        return (j < m) ? -1 : i - m;
    }
    vector<int> prefix_function(string s) {
        int n = (int)s.length();
        vector<int> pi(n, 0);
        for (int i = 1; i < n; i++) {
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j])
                j = pi[j-1];
            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }
        return pi;
    }
};

int main() {
    fast();

    Solution sol;
    string haystack = "abaaabaabcabaabafabaa";
    string needle = "abaabcabaabafaba";
    cout << sol.strStr(haystack, needle) << "\n"; // -1

    haystack = "leetcode";
    needle = "leeto";
    cout << sol.strStr(haystack, needle) << "\n"; // -1

    haystack = "isadsads";
    needle = "sad";
    cout << sol.strStr(haystack, needle) << "\n"; // 1
    return 0;
}

