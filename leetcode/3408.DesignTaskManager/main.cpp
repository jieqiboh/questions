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

class TaskManager {
public:
    priority_queue<vector<int>> pq; // max heap of [priority, taskId, userId]
    unordered_map<int,int> taskPriority; // maps taskId to priority
    unordered_map<int,int> taskUser; // maps taskId to UserId

    TaskManager(vector<vector<int>>& tasks) {
        for (vector<int> v : tasks) {
            int userId = v[0];
            int taskId = v[1];
            int priority = v[2];

            taskPriority[taskId] = priority;
            taskUser[taskId] = userId;
            pq.push({priority, taskId, userId});
        }
    }

    void add(int userId, int taskId, int priority) {
        taskPriority[taskId] = priority;
        taskUser[taskId] = userId;
        pq.push({priority, taskId, userId});
    }

    void edit(int taskId, int newPriority) {
        taskPriority[taskId] = newPriority;
        int userId = taskUser[taskId];
        pq.push({newPriority, taskId, userId});
    }

    void rmv(int taskId) {
        taskPriority.erase(taskId);
        taskUser.erase(taskId);
    }

    int execTop() {
        if (pq.empty()) return -1;
        vector<int> cur = pq.top();
        int curPriority = cur[0];
        int curTaskId = cur[1];

        while (taskPriority.find(curTaskId) == taskPriority.end() || taskPriority[curTaskId] != curPriority) {
            pq.pop();
            if (pq.empty()) return -1;
            cur = pq.top();
            curPriority = cur[0];
            curTaskId = cur[1];
        }

        // this is a valid top task
        int curUserId = cur[2];
        // remove this task
        pq.pop();
        taskPriority.erase(curTaskId);
        taskUser.erase(curTaskId);

        return curUserId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */

int main() {
    fast();

    return 0;
}

