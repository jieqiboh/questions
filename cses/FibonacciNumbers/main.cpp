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

// Multiply two generic n×n matrices modulo MOD
vector<vector<ll>> matMul(const vector<vector<ll>>& A,
                                 const vector<vector<ll>>& B) {
    int n = A.size();
    vector<vector<ll>> C(n, vector<ll>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            if (A[i][k] == 0) continue; // small optimization
            __int128 aik = A[i][k];
            for (int j = 0; j < n; j++) {
                C[i][j] = (C[i][j] + aik * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

vector<vector<ll>> matpow(vector<vector<ll>>& mat, ll exp) {
    // multiplies a mat by itself quickly
    int n = mat.size();

    // Base case: identity matrix
    if (exp == 0) {
        vector<vector<ll>> I(n, vector<ll>(n, 0));
        for (int i = 0; i < n; i++) I[i][i] = 1;
        return I;
    }

    if (exp % 2 == 0) {
        vector<vector<ll>> tmp = matpow(mat, exp / 2);
        return matMul(tmp, tmp);
    } else {
        vector<vector<ll>> tmp = matpow(mat, (exp-1) / 2);
        return matMul(mat, matMul(tmp, tmp));
    }
}

int main() {
    fast();

    ll n; cin >> n;
    vector<vector<ll>> mat = {{1,1},{1,0}};
    vector<vector<ll>> res = matpow(mat, n);
    cout << res[0][1];

    return 0;
}

