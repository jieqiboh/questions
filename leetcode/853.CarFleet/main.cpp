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
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // see neetcode for a good expln on the stack based soln
        unordered_map<int, int> speeds; // maps pos to speed
        for (int i = 0; i < position.size(); i++) {
            speeds[position[i]] = speed[i];
        }
        sort(position.begin(), position.end());

        stack<int> s; // contains positions
        s.push(position[position.size() - 1]);
        for (int i = position.size() - 2; i >= 0; i--) {
            int top = s.top();
            int iPos = position[i];
            double topFinishTime = (double)(target - top) / (double)speeds[top];
            double iFinishTime = (double)(target - iPos) / (double)speeds[iPos];
            if (iFinishTime <= topFinishTime) { // i reaches end or at the same time as top, means collision
                continue; // don't push iPos to the stack
            } else {
                s.push(iPos);
            }
        }
        return s.size();
    }
};

int main() {
    fast();

    Solution sol;
    int target = 12;
    vector<int> position = {10,8,0,5,3};
    vector<int> speed = {2,4,1,1,3};
    cout << sol.carFleet(target, position, speed) << "\n"; // 3

    target = 10;
    position = {6,8};
    speed = {2,3};
    cout << sol.carFleet(target, position, speed) << "\n"; // 2

    return 0;
}

