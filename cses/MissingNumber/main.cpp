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

int main() {
    fast();
    int n; cin >> n;
    vector<int> nums;
    for (int i = 1; i <= n; i++) {
        nums.push_back(i);
    }
    int cur;
    cin >> cur;
    for (int i = 1; i < n - 1; i++) {
        int tmp; cin >> tmp;
        cur ^= tmp; // xor
    }
    for (int i : nums) {
        cur ^= i;
    }
    cout << cur;
    return 0;
}

