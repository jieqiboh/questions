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
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto it = lower_bound(letters.begin(), letters.end(), target);
        if (it == letters.end()) {
            return letters[0];
        }
        return *it;
    }
};

int main() {
    fast();
    Solution sol;
    vector<char> letters = {'c', 'f', 'j'};
    char target = 'a';
    cout << sol.nextGreatestLetter(letters, target) << "\n"; // c

    letters = {'x', 'x', 'y', 'y'};
    target = 'z';
    cout << sol.nextGreatestLetter(letters, target) << "\n"; // x
    return 0;
}

