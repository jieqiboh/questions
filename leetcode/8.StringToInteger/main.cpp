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
    int myAtoi(string s) {
        // find first occurrence of sign or number
        int i = 0;
        while (s[i] == ' ' && i < s.size()) {
            i++;
        }
        bool isNeg = false;
        if (s[i] == '-') {
            isNeg = true;
            i++;
        } else if (s[i] == '+') {
            isNeg = false;
            i++;
        } else if (s[i] < 48 || s[i] > 57) { // not an ascii number
            return 0;
        }

        int j = i; // j is the end of the string
        while (s[j] >= 48 && s[j] <= 57 && j < s.size()) { // while s[j] is an ascii number
            j++;
        }
        // string [i, j) is the range
        if (j == i) return 0;
        string valString = s.substr(i, j - i);
        long actNum = 0;
        int k = 0;
        while (k < valString.size() && (-actNum > INT32_MIN || actNum < INT32_MAX)) {
            actNum = actNum * 10 + valString[k] - '0';
            k++;
        }
        if (isNeg) {
            long negActNum = -actNum;
            if (negActNum < INT32_MIN) return INT32_MIN;
            return int(negActNum);
        } else {
            if (actNum > INT32_MAX) return INT32_MAX;
            return int(actNum);
        }
    }
};

int main() {
    fast();

    Solution sol;
    string s = "   -42";
    cout << sol.myAtoi(s) << "\n";

    s = "1337c0d3";
    cout << sol.myAtoi(s) << "\n";

    s = "0-1";
    cout << sol.myAtoi(s) << "\n";

    s = "words and 987";
    cout << sol.myAtoi(s) << "\n";

    s = "-042";
    cout << sol.myAtoi(s) << "\n";

    s = "2147483648";
    cout << sol.myAtoi(s) << "\n"; // 2147483647

    s = "-21474836489";
    cout << sol.myAtoi(s) << "\n"; // -2147483648

    s = "+-43";
    cout << sol.myAtoi(s) << "\n"; // -2147483648

    s = "2000000000000000000000000000000000000000000";
    cout << sol.myAtoi(s) << "\n"; // 2147483647
    return 0;
}

