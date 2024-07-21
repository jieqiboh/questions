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
    int romanToInt(string s) {
        int val = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            // cout << c << " ";
            if (c == 'I') {
                if (i == s.size() - 1) {
                    val += 1;
                } else if (s[i + 1] == 'V') {
                    val += 4;
                    i++;
                } else if (s[i + 1] == 'X') {
                    val += 9;
                    i++;
                } else {
                    val += 1;
                }
            } else if (c == 'X') {
                if (i == s.size() - 1) {
                    val += 10;
                } else if (s[i + 1] == 'L') {
                    val += 40;
                    i++;
                } else if (s[i + 1] == 'C') {
                    val += 90;
                    i++;
                } else {
                    val += 10;
                }
            } else if (c == 'C') {
                if (i == s.size() - 1) {
                    val += 100;
                } else if (s[i + 1] == 'D') {
                    val += 400;
                    i++;
                } else if (s[i + 1] == 'M') {
                    val += 900;
                    i++;
                } else {
                    val += 100;
                }
            } else if (c == 'V') {
                val += 5;
            } else if (c == 'M') {
                val += 1000;
            } else if (c == 'L') {
                val += 50;
            } else if (c == 'D') {
                val += 500;
            }
        }
        return val;
    }
};

int main() {
    fast();

    Solution sol;

    string s = "MCMXCIV";

    cout << sol.romanToInt(s);



    return 0;
}

