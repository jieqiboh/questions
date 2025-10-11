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

    ll n; cin >> n;
    // let x be the sum of [1...n]
    ll x = (n * (n+1)) / 2;
    if (x % 2 != 0) {
        cout << "NO";
        return 0;
    }

    // otherwise keep adding the largest available number from [1, n] to a sum, keeping track of the numbers
    // when adding the largest available number exceeds n/2, then just add n/2 - sum to the set

    set<ll> numbers;
    ll halfn = x / 2;

    for (ll i = n; i >= 1; i--) {
        if (halfn < i) {
            if (halfn == 0) break;
            numbers.insert(halfn);
            break;
        } else {
            numbers.insert(i);
            halfn -= i;
        }
    }

    cout << "YES" << "\n";
    cout << numbers.size() << "\n";
    for (ll x : numbers) {
        cout << x << " ";
    }
    cout << "\n";
    cout << n - numbers.size() << "\n";
    for (int i = n; i >= 1; i--) {
        if (numbers.find(i) == numbers.end()) {
            cout << i << " ";
        }
    }

    return 0;
}

