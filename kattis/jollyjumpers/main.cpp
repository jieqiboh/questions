#include <cstdio>
#include <iostream>
#include <unordered_map>
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

void printVec(vector<bool>);

int main() {
    // Your code goes here
    // jolly if all differences take up values [1,n-1]
    int n;

    while (cin >> n) {
        vector<int> v(n);
        vector<bool> seen(n, false); // initialise an array of false booleans
        
        for (auto& i:v) { // for each entry in v, cin in it
            cin >> i;
        }

        for (int i=1;i<n;i++) {
            int diff = abs(v[i] - v[i-1]);
            if ( diff >= 1 && diff < n) {
                seen[diff-1] = true;
            }
        }
        
        bool jolly = true;
        for (int i = 0;i<n-1;i++) {
            bool b = seen[i];
            jolly &= b;
        }
        if (jolly) {
            cout << "Jolly" << endl;
        } else {
            cout << "Not jolly" << endl;
        }
    }
    return 0;
}

void printVec(vector<bool> x) {
    for (bool b : x) {
        cout << b << " ";
    }
    cout << endl;
}
