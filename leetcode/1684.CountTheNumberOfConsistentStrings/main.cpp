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
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> allowed_set; // set of allowed chars

        for (char c : allowed) allowed_set.insert(c);

        int res = 0;
        for (string s : words) {
            int isValid = true;
            for (char c : s) {
                if (allowed_set.find(c) == allowed_set.end()) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) res++;
        }
        return res;
    }
};

int main() {
    fast();

    return 0;
}

