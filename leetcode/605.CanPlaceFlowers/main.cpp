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

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i = 0; i < flowerbed.size(); i++) {
            int leftPlot = (i == 0) ? 0 : flowerbed[i - 1];
            int rightPlot = (i == flowerbed.size() - 1) ? 0 : flowerbed[i + 1];

            if (leftPlot == 0 && rightPlot == 0 && flowerbed[i] != 1) {
                flowerbed[i] = 1;
                n--;
            }
        }
        return n == 0;
    }
};

int main() {
    fast();

    vector<int> flowerbed = {0,0,1,0,0};
    int n = 2;
    Solution sol;
    cout << sol.canPlaceFlowers(flowerbed, n) << "\n"; // 1

    return 0;
}

