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
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        // heaps are max heaps by default (idx, val)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> basketspq;
        for (int i = 0; i < baskets.size(); i++) {
            basketspq.emplace(i, baskets[i]);
        }

        int res = 0;
        for (int i = 0; i < fruits.size(); i++) {
            int curFruit = fruits[i];
            vector<pair<int,int>> tmp;
            while (!basketspq.empty()) {
                if (basketspq.top().second >= curFruit) {
                    res++;
                    basketspq.pop();
                    break;
                } else {
                    tmp.push_back(basketspq.top());
                    basketspq.pop();
                }
            }
            for (auto x : tmp) {
                basketspq.push(x);
            }
        }
        return fruits.size() - res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> fruits = {4,2,5};
    vector<int> baskets = {3,5,4};
    cout << sol.numOfUnplacedFruits(fruits, baskets) << "\n";

    return 0;
}

