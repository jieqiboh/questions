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
using ll = long long;
using i128 = __int128_t;

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int const maxN = 2e5;
ll mod = 1e9 + 7;
vector<bool> is_prime(maxN);
vector<int> primes;
unordered_map<int,int> ans;

// sieve of eratosthenes
void init_primes(){
    for(int i = 2; i < maxN; i++)   is_prime[i] = true;
    for(int i = 2; i < maxN; i++){
        if(is_prime[i]){
            primes.push_back(i);
            for(int j = 2 * i; j < maxN; j += i)
                is_prime[j] = false;
        }
    }
}

ll dfs(ll start, vector<ll>& v, vector<ll>& visited) {
    // performs a dfs, updates visited and returns the size of the cycle
    ll cur = start;
    ll sz = 0;
    while (!visited[cur]) {
        visited[cur] = 1;
        sz++;
        cur = v[cur];
    }
    return sz;
}

void prime_factor(int x) {
    // obtain the largest exponent in the prime factorisation of a number
    for (int i = 0; i < (int) primes.size() && primes[i] <= x; i++) {
        int p = primes[i];
        int num_divisions = 0;
        while (x % p == 0) {
            x /= p;
            num_divisions++;
        }

        if (num_divisions > 0) {
            ans[p] = max(ans[p], num_divisions);
        }
    }
}

int main() {
    fast();

    init_primes(); // init primes

    ll n; cin >> n;

    vector<ll> v(n+1);
    for (ll i = 0; i < n; i++) {
        cin >> v[i+1];
    }

    set<ll> cycles;
    vector<ll> visited(n+1, 0);
    for (ll i = 1; i <= n; i++) {
        if (!visited[i]) {
            ll len = dfs(i, v, visited);
            prime_factor(len);
        }
    }

    ll res = 1;
    for (auto const& [prime, power] : ans) {
        res *= pow(prime, power);
        res %= mod;
    }

    cout << res;

    return 0;
}

