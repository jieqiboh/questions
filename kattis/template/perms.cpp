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

    std::string letters = "LLLCCCVVV";

    // Sorting the string is important for using next_permutation
    std::sort(letters.begin(), letters.end());

    // Generating permutations starting from 'LLL'
    do {
        std::cout << letters.substr(0, 3) << endl;
    } while (std::next_permutation(letters.begin(), letters.end()));

    return 0;
}

