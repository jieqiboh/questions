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

int main() {
    fast();
    int rnds = 0; // cur round

    set<int> st;
    int n; cin >> n;
//    vector<int> nums(n);
//    for (int i = 0; i < nums.size(); i++) {
//        cin >> nums[i];
//    }

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (st.find(x-1) == st.end()) { // prev value comes after
            rnds++;
        }
        st.insert(x);
    }
    cout << rnds;

    return 0;
}

