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

bool isValid(int x, vector<int>& ppl, int sum) {
    // Checks if this x will cause more than half to have < avg wealth
    int newAvg = (x + sum) / ppl.size();
    int cur = 0;

    for (int i = 0; i < ppl.size(); i++) {
        if (ppl[i] < newAvg) cur++;
    }

    // Return true if more than half have less than new average
    return cur <= (ppl.size() / 2);
}

int binSearch(vector<int>& ppl, int sum) {
    int l = 0;
    int r = INT32_MAX;

    while (l < r) { // Use l < r to avoid infinite loop
        int mid = l + (r - l) / 2;

        if (isValid(mid, ppl, sum)) {
            r = mid; // valid means we can search lower
        } else {
            l = mid + 1; // not valid, search higher
        }
    }
    return l; // l should be the first invalid point
}

int main() {
    ios::sync_with_stdio(false); // Fast input/output
    cin.tie(nullptr); // Untie cin from cout

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> ppl(n);

        for (int i = 0; i < n; i++) {
            cin >> ppl[i]; // Directly read into ppl vector
        }

        if (n == 1) {
            cout << -1 << "\n"; // Not enough people to give gold
            continue;
        }

        int sum = accumulate(ppl.begin(), ppl.end(), 0);
        int res = binSearch(ppl, sum);
        cout << res << "\n";
    }

    return 0;
}

