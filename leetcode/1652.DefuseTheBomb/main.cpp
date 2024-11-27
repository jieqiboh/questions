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

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n, 0);
        if (k > 0) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < k; j++) {
                    res[i] += code[(i + 1 + j) % n];
                }
            }
        } else if (k < 0) {
            int abs_k = abs(k);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < abs_k; j++) {
                    res[i] += code[(i - 1 - j + n) % n];
                }
            }
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> code = {5,7,1,4};
    int k = 3;
    vector<int> res = sol.decrypt(code, k);
    for (int x : res) {
        cout << x << " ";
    }
    cout << "\n";
//
//    res = sol.decrypt(code, 0);
//    for (int x : res) {
//        cout << x << " ";
//    }
//    cout << "\n";

    code = {2,4,9,3};
    k = -2;
    res = sol.decrypt(code, k);
    for (int x : res) {
        cout << x << " ";
    }
    cout << "\n";


    return 0;
}

