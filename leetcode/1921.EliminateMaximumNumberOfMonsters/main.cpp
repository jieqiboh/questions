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
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        // ret max no. of monsters to eliminate
        // compute time taken for each monster to reach in minutes
        vector<double> time;
        for (int i = 0; i < dist.size(); i++) {
            time.push_back((double)dist[i] / (double)speed[i]);
        }
        sort(time.begin(), time.end());

        int res = 1;
        for (int i = 1; i < time.size(); i++) {
            if (time[i] <= i) {
                return res;
            }
            res++;
        }

        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> dist = {1,3,4};
    vector<int> speed = {1,1,1};
    cout << sol.eliminateMaximum(dist, speed) << "\n"; // 3

    dist = {3,2,4};
    speed = {5,3,2};
    cout << sol.eliminateMaximum(dist, speed) << "\n";

    dist = {3,5,7,4,5};
    speed = {2,3,6,3,2};
    cout << sol.eliminateMaximum(dist, speed) << "\n";

    dist = {1,1,2,3};
    speed = {1,1,1,1};
    cout << sol.eliminateMaximum(dist, speed) << "\n";
    return 0;
}

