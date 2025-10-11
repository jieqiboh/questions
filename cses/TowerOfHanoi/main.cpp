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

vector<string> res;
void toh(int n, int src, int dst) {
    if (n == 1) {
        string s = to_string(src) + " " + to_string(dst);
        res.push_back(s);
        return;
    }

    int mid = 6 - src - dst;
    toh(n-1, src, mid);
    string s = to_string(src) + " " + to_string(dst);
    res.push_back(s);
    toh(n-1, mid, dst);
}

int main() {
    fast();

    int n; cin >> n;
    toh(n, 1, 3);

    cout << res.size() << "\n";
    for (string s : res) {
        cout << s << "\n";
    }

    return 0;
}

