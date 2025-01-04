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
    long long pickGifts(vector<int>& gifts, int k) {
        for (int i = 0; i < k; i++) {
            int maxIdx = 0;
            int maxVal = gifts[0];
            for (int j = 0; j < gifts.size(); j++) {
                if (gifts[j] > maxVal) {
                    maxIdx = j;
                    maxVal = gifts[j];
                }
            }

            gifts[maxIdx] = floor(sqrt(gifts[maxIdx]));
        }
        long long res = accumulate(gifts.begin(), gifts.end(), 0);
        return res;
    }
};

int main() {
    fast();

    return 0;
}

