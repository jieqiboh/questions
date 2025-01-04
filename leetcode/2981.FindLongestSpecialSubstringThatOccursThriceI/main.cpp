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
#define ll long long

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string,int> m;
        set<string> substrs;

        int i = 0;
        string cur = "";
        while (i < s.size()) {
            if (cur[0] == s[i]) {
                continue;
            } else {

                cur = s[i];

            }
            i++;
        }

    }
};

int main() {
    fast();

    return 0;
}

