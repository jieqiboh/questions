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

    ll n;
    cin>>n;
    ll x[n];
    set<ll> s;
    for(int i=0;i<n;i++) {
        cin>>x[i];
        s.insert(x[i]);
    }
    cout<<s.size();

    return 0;
}
