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

    // Use square root decomposition

    int n; cin >> n; // number of children
    int k; cin >> k; // steps to jump

    vector<vector<int>> v;
    int rt = sqrt(n);
    int cnt = 0;
    vector<int> tmp;
    for (int i = 1; i <= n; i++) { // init array
        if (cnt > rt) {
            cnt = 0;
            v.push_back(tmp);
            tmp.clear();
        }
        tmp.push_back(i);
        cnt++;
    }
    if (!tmp.empty()) v.push_back(tmp);
    for (vector<int> vi : v) {
        for (int i : vi) {
            cout << i << " ";
        }
        cout << "\n";
    }



    return 0;
}

