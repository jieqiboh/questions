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
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int> m; // maps number to num occurrences
        for (int i = 0; i < arr.size(); i++) {
            int num = arr[i];
            m[num]++;
        }
        for (int i = 0; i < arr.size(); i++) {
            int num = arr[i];
            if (num == 0) {
                if (m[0] > 1) return true;
            } else {
                if (m.find(num * 2) != m.end()) return true;
            }
        }
        return false;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> arr = {10,2,5,3};
    cout << sol.checkIfExist(arr) << "\n"; // 1

    arr = {3,1,7,11};
    cout << sol.checkIfExist(arr) << "\n"; // 0

    arr = {-2,0,10,-19,4,6,-8};
    cout << sol.checkIfExist(arr) << "\n"; // 0

    arr = {0,1,5,0};
    cout << sol.checkIfExist(arr) << "\n"; // 1

    arr = {0};
    cout << sol.checkIfExist(arr) << "\n"; // 0
    return 0;
}

