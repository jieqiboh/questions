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
    string addBinary(string a, string b) {
        if (a.length() > b.length()) {
            b.insert(0, a.length() - b.length(), '0');
        } else if (b.length() > a.length()) {
            a.insert(0,  b.length() - a.length(), '0');
        }

        bool carry = false;
        string res;

        int length = max(a.length(), b.length());
        for (int i = length - 1; i >= 0; i--) {
            if (a[i] == '1' && b[i] == '1') {
                if (carry) {
                    res = '1' + res;
                } else {
                    res = '0' + res;
                }
                carry = true;
            } else if (a[i] == '0' && b[i] == '0') {
                if (carry) {
                    res = '1' + res;
                    carry = false;
                } else {
                    res = '0' + res;
                }
            } else { // 1 0
                if (carry) {
                    res = '0' + res;
                    carry = true;
                } else {
                    res = '1' + res;
                }
            }
        }
        if (carry) {
            return "1" + res;
        } else {
            return res;
        }
    }
};

int main() {
    fast();
    Solution sol;
    string a = "11";
    string b = "1";
    cout << sol.addBinary(a, b) << "\n";

    return 0;
}

