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

struct Compare {
    bool operator()(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
};

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int target = times[targetFriend][0]; // targetFriend's arrival time
        sort(times.begin(), times.end()); // sort by arrival time
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq; // minheap according to end time; leave time, chair
        priority_queue<int, vector<int>, greater<>> chairs; // smallest available chairs

        for (int i = 0; i <= target; i++) {
            chairs.push(i);
        }

        for (int i = 0; i <= target; i++) {
            vector<int> v = times[i];
            int arrTime = v[0]; // current time

            // remove all friends that have left and push their chairs back into chairs pq
            while (!pq.empty() && pq.top()[0] <= arrTime) {
                chairs.push(pq.top()[1]);
                pq.pop();
            }
            if (arrTime == target) return chairs.top();
            pq.push({v[1], chairs.top()});
            chairs.pop();
        }
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> times = {{1,4},{2,3},{4,6}};
    int targetFriend = 1;
    cout << sol.smallestChair(times, targetFriend) << "\n"; // 1

    times = {{3,10},{1,5},{2,6}};
    targetFriend = 0;
    cout << sol.smallestChair(times, targetFriend) << "\n";  // 2

    return 0;
}

