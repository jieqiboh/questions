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
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        stack<int> s;
        unordered_set<int> visited;

        for (int i : rooms[0]) {
            s.push(i);
        }
        visited.insert(0); // no point revisiting room 0
        while (!s.empty()) {
            int curNode = s.top();
            s.pop();

            if (visited.find(curNode) == visited.end()) {
                visited.insert(curNode);
            }

            for (int i : rooms[curNode]) {
                if (visited.find(i) == visited.end()) {
                    s.push(i);
                }
            }
        }
        return visited.size() == rooms.size();
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> rooms = {{1},{2},{3},{}};
    cout << sol.canVisitAllRooms(rooms) << "\n"; // 1

    rooms = {{1,3},{3,0,1},{2},{0}};
    cout << sol.canVisitAllRooms(rooms) << "\n"; // 0
    return 0;
}

