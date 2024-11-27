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

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> pref(s.size() + 1, 0);
        for (vector<int> shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            if (shift[2] == 0) {
                pref[start]--;
                pref[end + 1]++;
            } else {
                pref[start]++;
                pref[end + 1]--;
            }
        }
        // compute prefix sum
        for (int i = 1; i < pref.size(); i++) {
            pref[i] += pref[i - 1];
        }
        for (int i = 0; i < pref.size(); i++) {
            int increaseBy=(s[i]-'a'+pref[i])%26;
            increaseBy=(increaseBy+26)%26;
            s[i]='a'+increaseBy;
        }
        return s;
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> shifts = {{0,1,0},{1,2,1},{0,2,1}};
    string s = "abc";
    cout << sol.shiftingLetters(s, shifts) << "\n"; // ace

    s = "dztz";
    shifts = {{0,0,0},{1,1,1}};
    cout << sol.shiftingLetters(s, shifts) << "\n"; // catz

    return 0;
}

