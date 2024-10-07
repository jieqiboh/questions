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
    int getLucky(string s, int k) {
        string conv_string = convert(s);
        for (int i = 0; i < k; i++) {
            conv_string = transform(conv_string);
        }
        return stoi(conv_string);
    }
    string transform(string s) {
        int res = 0;
        for (char c : s) {
            res += c - '0';
        }
        return to_string(res);
    }
    string convert(string s) {
        string res = "";
        for (char c : s) {
            res += to_string(c - 96);
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    string s = "zbax";
    int k = 2;
    cout << sol.getLucky(s, k) << "\n";

    return 0;
}

