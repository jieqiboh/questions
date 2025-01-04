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
    double gain(double students, double total) {
        double curRatio = static_cast<double>(students) / total; // Cast only one operand
        double newRatio = static_cast<double>(students + 1) / (total + 1);
        return newRatio - curRatio;
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<vector<double>> pq; // gain, students, total

        for (vector<int> cls : classes) {
            double stu = cls[0];
            double tot = cls[1];
            pq.push({gain(stu,tot), stu, tot});
        }

        for (int i = 0; i < extraStudents; i++) {
            vector<double> top = pq.top();
            pq.pop();

            double stu = top[1] + 1;
            double tot = top[2] + 1;
            pq.push({gain(stu,tot), stu, tot});
        }

        double res = 0.0;
        while (!pq.empty()) {
            vector<double> top = pq.top();
            pq.pop();
            res += (top[1] / top[2]);
        }
        return res / static_cast<double>(classes.size());
    }
};

int main() {
    fast();
    Solution sol;
    vector<vector<int>> classes = {{1,2},{3,5},{2,2}};
    int extraStudents = 2;
    cout << sol.maxAverageRatio(classes, extraStudents) << "\n"; //

    return 0;
}

