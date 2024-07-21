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
    string convert(string s, int numRows) {
        // numRows
        if (numRows == 1) return s;

        vector<vector<char>> arrs(numRows);

        int i = 0;
        int j = 0;
        while (i < s.size()) {
            while (j < numRows - 1 && i < s.size()) {
                // cout << s[i] << " " << i << " " << j << "\n";
                arrs[j].push_back(s[i]);
                j++;
                i++;
            }
            while (j > 0 && i < s.size()) {
                // cout << s[i] << " " << i << " " << j << "\n";
                arrs[j].push_back(s[i]);
                j--;
                i++;
            }
        }

        string res = "";
        for (auto& a : arrs) {
            for (auto& x : a) {
                // cout << x << " ";
                res += x;
            }
        }

        return res;
        
    }
};

int main() {
    fast();

    Solution sol;

    string s = "PAYPALISHIRING";
    int n = 3;

    cout << sol.convert(s, n);

    return 0;
}
