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
    bool canReach(vector<int>& arr, int start) {
        // do a bfs
        queue<int> q; // contains pos

        unordered_set<int> visited;
        visited.insert(start);
        q.push(start);

        while (!q.empty()) {
            auto cur = q.front();
            int pos = cur;
            q.pop();

            if (arr[pos] == 0) return true;

            int moveFront = pos + arr[pos];
            int moveBack = pos - arr[pos];

            if (moveFront <= arr.size() - 1 && visited.find(moveFront) == visited.end()) { // in-bounds + unvisited
                visited.insert(moveFront);
                q.push(moveFront);
            }

            if (moveBack >= 0 && visited.find(moveBack) == visited.end()) { // in-bounds + unvisited
                visited.insert(moveBack);
                q.push(moveBack);
            }
        }
        return false;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> arr = {4,2,3,0,3,1,2};
    int start = 5;
    cout << sol.canReach(arr, start) << "\n"; // 1

    return 0;
}

