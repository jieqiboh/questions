#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <bitset>
#include <utility>

using namespace std;

#define uset unordered_set
#define umap unordered_map
#define endl '\n'

typedef vector<int> vi;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

template <typename T> void printVec(vector<T> s) {
    for (T x : s) {
        cout << x;
    }
    cout << endl;
}

int main() {
    fast();

    // generate all primes between [1,10^9]
    // [1,10^9]
    //
    int flag;
    for (int i = 0; i <= 1e9; i++) {
        // Skip 0 and 1 as they are
        // neither prime nor composite
        if (i == 1 || i == 0)
            continue;

        // flag variable to tell
        // if i is prime or not
        flag = 1;

        for (int j = 2; j <= i / 2; ++j) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }

        // flag = 1 means i is prime
        // and flag = 0 means i is not prime
        if (flag == 1)
            cout << i << " ";
    }
    vector<bool> AliceWins(1e9, false);
    for (int i = 1; i < AliceWins.size(); i++) {
        // number is i, compute if Alice is able to win
    }
    // 2 3 5 7 11 13 17 19
    // For each number, if A can rm an amt s.t. the remaining amt is where the first person loses, A wins
    // If the number is 1 less than a prime, A also wins
    // 1 - Alice: 1
    // 2 - Alice: 2
    // 3 - Bob:   2 1
    // 4 - Alice: 4
    // 5 - Bob:


    return 0;
}

