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
        for (int i = 0; i < haystack.size(); i++) {
            if (haystack[i] == needle[0]) {
                if (haystack.substr(i, needle.length()) == needle) {
                    return i;
                }
            }
        }
        return -1;
    }
};

int main() {
    fast();

    Solution sol;
    string haystack = "leetcode";
    string needle = "leeto";
    cout << sol.strStr(haystack, needle) << "\n"; // -1

    haystack = "isadsads";
    needle = "sad";
    cout << sol.strStr(haystack, needle) << "\n"; // 1
    return 0;
}

