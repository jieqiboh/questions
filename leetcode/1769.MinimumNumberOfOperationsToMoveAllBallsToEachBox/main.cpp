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
    vector<int> minOperations(string boxes) {
        unordered_set<int> idxes;

        for (int i = 0; i < boxes.size(); i++) {
            if (boxes[i] == '1') {
                idxes.insert(i);
            }
        }
        vector<int> res(boxes.size());
        for (int i = 0; i < boxes.size(); i++) {
            int val = 0;
            for (int idx : idxes) {
                val += abs(idx - i);
            }
            res[i] = val;
        }
        return res;
    }
};

int main() {
    fast();

    return 0;
}

