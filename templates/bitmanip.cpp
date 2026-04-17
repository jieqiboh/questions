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

int  countBits(ll n)      { return __builtin_popcountll(n); }  // number of set bits
bool isPow2(ll n)         { return n > 0 && (n & (n - 1)) == 0; }
bool checkBit(ll n, int k){ return (n >> k) & 1; }             // is kth bit set?
ll   setBit(ll n, int k)  { return n | (1LL << k); }
ll   clearBit(ll n, int k){ return n & ~(1LL << k); }
ll   toggleBit(ll n, int k){ return n ^ (1LL << k); }
ll   lowBit(ll n)         { return n & (-n); }                 // isolate lowest set bit
int  floorLog2(ll n)      { return 63 - __builtin_clzll(n); }  // index of highest set bit

// XOR from 0..n in O(1)
ll xorUpTo(ll n) {
    switch (n % 4) {
        case 0: return n;
        case 1: return 1;
        case 2: return n + 1;
        case 3: return 0;
    }
    return 0;
}

// XOR of range [l, r]
ll xorRange(ll l, ll r) { return xorUpTo(r) ^ xorUpTo(l - 1); }

// ─── Bit Iteration ───────────────────────────────────────────────────────────

// Iterate over every bit position (0..63), set or not
// for (int k = 0; k < 64; k++) { if (checkBit(n, k)) { /* bit k is set */ } }

// Iterate over all subsets of a bitmask (excluding empty set)
// for (ll sub = mask; sub > 0; sub = (sub - 1) & mask) { /* use sub */ }

// ─────────────────────────────────────────────────────────────────────────────

int main() {
    fast();

    return 0;
}