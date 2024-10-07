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
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int,set<int>> x;
        unordered_map<int, set<int>> y;
        x.reserve(10000);
        y.reserve(10000);
        pair<int,int> curPos = {0,0};

        for (vector<int> ob : obstacles) {
            x[ob[0]].insert(ob[1]);
            y[ob[1]].insert(ob[0]);
        }

        // n e s w
        vector<char> dirns = {'n','e','s','w'};
        int dir = 0;

        int maxDist = 0;
        for (int cmd : commands) {
            if (cmd == -1) {
                dir = (dir + 1) % 4;
            } else if (cmd == -2) {
                dir = (dir + 3) % 4;
            } else {
                int xcoord = curPos.first;
                int ycoord = curPos.second;
                if (dir == 0) { // n up
                    auto it = x[xcoord].upper_bound(ycoord);
                    if (it != x[xcoord].end() && *it<=ycoord+cmd) {
                        curPos = {xcoord, *it-1};
                    } else {
                        curPos = {xcoord, ycoord+cmd};
                    }
                } else if (dir == 1) { // e right
                    auto it = y[ycoord].upper_bound(xcoord); // find the first x val > cur x
                    if (it != y[ycoord].end() && *it<=xcoord+cmd) {
                        curPos = {*it-1, ycoord};
                    } else {
                        curPos = {xcoord+cmd, ycoord};
                    }
                } else if (dir == 2) { // s down
                    auto it = upper_bound(x[xcoord].rbegin(), x[xcoord].rend(), ycoord, greater<>());
                    if (it != x[xcoord].rend() && *it>=ycoord-cmd) {
                        curPos = {xcoord, *it+1};
                    } else {
                        curPos = {xcoord, ycoord-cmd};
                    }
                } else if (dir == 3) { // w left
                    auto it = upper_bound(y[ycoord].rbegin(), y[ycoord].rend(), xcoord, greater<>());
                    if (it != y[ycoord].rend() && *it>=xcoord-cmd) {
                        curPos = {*it+1, ycoord};
                    } else {
                        curPos = {xcoord-cmd, ycoord};
                    }
                }
            }
            int cur = pow(curPos.first,2) + pow(curPos.second, 2);
            maxDist = max(maxDist, cur);
        }
        return maxDist;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> commands = {4,-1,4,-2,4};
    vector<vector<int>> obstacles = {{2,4}};
    cout << sol.robotSim(commands, obstacles) << "\n"; // 65

    commands = {6,-1,-1,6};
    obstacles = {};
    cout << sol.robotSim(commands, obstacles) << "\n"; // 36

    commands = {-2,8,3,7,-1};
    obstacles = {{-4,-1},{1,-1},{1,4},{5,0},{4,5},{-2,-1},{2,-5},{5,1},{-3,-1},{5,-3}};
    cout << sol.robotSim(commands, obstacles) << "\n"; // 324
    return 0;
}

