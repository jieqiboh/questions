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

const int MOD = 1e9 + 7;

int main() {
    fast();
    int n, k; cin >> n >> k;
    int x, a, b, c; cin >> x >> a >> b >> c;

    vector<int> w(k);
    int head = 0;

    long long last = x; // represents the last element of the circular buffer

    w[0] = last;
    long long sum = last;
    for (int i = 1; i < k; i++) {
        last = ((last * a) + b) % c;
        w[i] = last;
        sum += last;
    }

    long long ans = sum;

    for (int i = k; i < n; i++) {
        long long next = ((last * a) + b) % c;

        int out = w[head];
        sum += next - out;
        w[head] = next;
        head = (head + 1) % k;

        ans ^= sum;
        last = next;
    }

    cout << ans;
    return 0;
}

