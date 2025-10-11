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
    cin.tie(NULL);
    cout.tie(NULL);
}

const ll P = 31;
const ll M = 1e9 + 9;

int main() {
    fast();

    string s;
    cin >> s;
    // we do a rolling hash from the start and from the end

    ll frontRH = 0;
    ll backRH = 0;

    // precompute the P^i
    vector<ll> powP(s.size(), 1);
    for (int i = 1; i < powP.size(); i++) {
        powP[i] = (P * powP[i - 1]) % M;
    }

    for (int i = 0; i < s.size() - 1; i++) {
        int l = s[i] - 'a' + 1;
        int r = s[s.size() - 1 - i] - 'a' + 1;

        frontRH = (frontRH + l * powP[i]) % M;
        backRH = (backRH * P + r) % M;
        if (frontRH == backRH) cout << i + 1 << " ";
    }

    return 0;
}

