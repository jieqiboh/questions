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
    bool lemonadeChange(vector<int>& bills) {
        // greedily give out the bills with the largest denominations first
        // so that we have more leeway to give change to subsequent customers
        // 10 - give 5
        // 20 - give 5 5 5 / 10 5
        umap<int, int> change; // maps denoms to their counts
        for (int i = 0; i < bills.size(); i++) {
//            cout << bills[i] << " ";
//            cout << "Change 5: " << change[5] << "\n";
            if (bills[i] == 5) {
                change[5]++;
            } else if (bills[i] == 10) {
                if (change[5] >= 1) {
                    change[5]--;
                    change[10]++;
                } else {
                    return false;
                }
            } else if (bills[i] == 20) {
                if (change[10] >= 1 && change[5] >= 1) {
                    change[10]--;
                    change[5]--;
                } else if (change[5] >= 3) {
                    change[5] -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    fast();

    vector<int> bills = {5,5,5,10,20};

    Solution sol;

    cout << sol.lemonadeChange(bills);

    return 0;
}

