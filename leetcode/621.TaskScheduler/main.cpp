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

struct Compare {
    bool operator()(pair<char, int>& a, pair<char, int>& b) {
        return a.second > b.second;  // Compare based on the second element (index), lower comes first
    }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        queue<pair<int, int>> q; // contains distinct char counts and their next available time
        priority_queue<int> pq; // each distinct int represents the count of a char

        // pq is a maxheap that represents tasks available for processing
        // q contains tasks waiting for the next available time

        unordered_map<char, int> m;
        for (int i = 0; i < tasks.size(); i++) {
            m[tasks[i]]++;
        }
        for (auto& p : m) {
            pq.push(p.second - 1);
        }
        int time = 1;

        while (!pq.empty() || !q.empty()) { // both have to be empty
            if (!q.empty()) { // check if any tasks ready to be processed
                pair<int,int> front = q.front();
                if (front.second == time) { // task can be moved from q to pq
                    pq.push(front.first);
                    q.pop();
                }
            }

            if (!pq.empty()) { // tasks are ready for processing
                int top = pq.top();
                pq.pop();

                if (top > 0) { // push to q again if task still available
                    q.push(make_pair(top - 1, time + n + 1));
                }
            }
            time++;
        }
        return time - 1;
    }
};

int main() {
    fast();
    Solution sol;
    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;
    cout << sol.leastInterval(tasks, n) << "\n"; // 8

    tasks = {'A','A','A','B','B','B'};
    n = 3;
    cout << sol.leastInterval(tasks, n) << "\n"; // 10

    tasks = {'A','B','A'};
    n = 2;
    cout << sol.leastInterval(tasks, n) << "\n"; // 4
    return 0;
}

