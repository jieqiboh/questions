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
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;

        while (j < t.size() && i < s.size()) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }

        return i == s.size(); 
    }
};

int main() {
    fast();


    Solution sol;
    string s = "ace";
    string t = "abcde";

    cout << sol.isSubsequence(s, t);



    return 0;
}

