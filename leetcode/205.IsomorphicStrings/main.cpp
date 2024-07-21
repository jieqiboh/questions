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
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s_t;
        unordered_map<char, char> t_s;

        for (int i = 0; i < s.size(); i++) {
            if (s_t.find(s[i]) == s_t.end() && t_s.find(t[i]) == t_s.end()) { // char not seen before
                s_t[s[i]] = t[i];
                t_s[t[i]] = s[i];
            } else {
                if (s_t[s[i]] != t[i]) return false;
            }
        }
        return true;
    }
};

int main() {
    fast();

    Solution sol;

    string s = "egg";

    string t = "add";

    cout << sol.isIsomorphic(s, t);

    return 0;
}

