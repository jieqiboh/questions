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

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> freqMap;
        for (int i : arr) {
            freqMap[i]++;
        }
        unordered_set<int> freqSet; // set of int frequencies
        for (pair<int,int> p : freqMap) {
            if (freqSet.find(p.second) != freqSet.end()) {
                return false;
            }
            freqSet.insert(p.second);
        }
        return true;
    }
};

int main() {
    fast();

    return 0;
}

