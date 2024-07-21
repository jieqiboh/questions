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

using namespace std;

#define uset unordered_set
#define umap unordered_map
#define endl '\n'

typedef vector<int> vi;
typedef long long ll;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        // some print statements
        cout << "gas is:  ";
        for (auto& x : gas) {
            cout << x << " ";
        }
        cout << "\n";
        cout << "cost is: ";
        for (auto& x : cost) {
            cout << x << " ";
        }
        cout << "\n";

        vector<int> net_gas(gas.size());
        for (int i = 0; i < gas.size(); i++) {
            net_gas[i] = gas[i] - cost[i];
        }

        int k = 0;
        int i = 0;
        while (k < gas.size()) {
            int fuel = 0;
            bool success = true;
            cout << "idx at start: " << i << "\n";
            for (int j = 0; j < gas.size(); j++) {
                k++;
                int idx = (i + j) % gas.size();
                fuel += net_gas[idx];
                cout << fuel << " ";
                if (fuel < 0) {
                    cout << "idx at fail: " << idx << "\n";
                    i = idx + 1;
                    success = false;
                    break;
                }
            }
            cout << "\n";
            if (success) return i;
        }
        return -1;
    };
};

int main() {
    fast();

    Solution sol;
//    vector<int> gas1 = {1,2,3,4,5};
//    vector<int> cost1 = {3,4,5,1,2};
//
//    cout << sol.canCompleteCircuit(gas1, cost1) << "\n";
//
//    vector<int> gas2 = {2,3,4};
//    vector<int> cost2 = {3,4,3};
//
//    cout << sol.canCompleteCircuit(gas2, cost2) << "\n";

    vector<int> gas3 = {0,0,0,0,0,0};
    vector<int> cost3= {0,0,0,0,1,0};

    cout << sol.canCompleteCircuit(gas3, cost3) << "\n";

    return 0;
}

