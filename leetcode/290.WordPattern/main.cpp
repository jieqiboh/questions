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
    bool wordPattern(string pattern, string s) {
        istringstream ss(s);

        vector<string> v;
        while (getline(ss, s, ' ')) {
            v.push_back(s);
        }

        if (pattern.size() != v.size()) return false;

        unordered_map<char,string> cs; // maps pattern chars to strings
        unordered_map<string, char> sc; // maps strings to pattern chars
        for (int i = 0; i < pattern.size(); i++) {
            if (cs.find(pattern[i]) == cs.end() && sc.find(v[i]) == sc.end()) { // pattern char not seen before
                cs[pattern[i]] = v[i];
                sc[v[i]] = pattern[i];
            } else { // pattern char seen before
                if (cs[pattern[i]] != v[i]) return false;
            }
        }
        return true;

    }
};

int main() {
    fast();

    Solution sol;
    string pattern = "abba";
    string s = "dog cat cat dog";

    cout << sol.wordPattern(pattern, s);

    pattern = "abba";
    s = "dog cat cat fish";

    cout << sol.wordPattern(pattern, s);

    return 0;
}

