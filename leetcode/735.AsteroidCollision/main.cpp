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
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        s.push(asteroids[0]);

        for (int i = 1; i < asteroids.size(); i++) {
            // collisions only if top +ve, a -ve
            bool isBroken = false; // whether a is broken
            int a = asteroids[i];
            if (s.empty()) {
                s.push(a);
                continue;
            }
            int top = s.top();
            while ((top > 0) && (a < 0) && !isBroken) { // collision
                if (abs(top) > abs(a)) { // top is bigger
                    isBroken = true;
                    break;
                } else if (abs(top) < abs(a)) { // a is bigger
                    s.pop();
                    if (s.empty()) break;
                    top = s.top();
                } else { // equal asteroids
                    isBroken = true;
                    s.pop();
                    break;
                }
            }
            if (!isBroken) s.push(a);
        }
        vector<int> res = {};
        while (!s.empty()) {
            res.insert(res.begin(), s.top());
            s.pop();
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    vector<int> asteroids = {5,10,-5};
    vector<int> res = sol.asteroidCollision(asteroids);
    for (int i : res) {
        cout << i << " "; // 5, 10
    }
    cout << "\n";

    asteroids = {10,2,-5};
    res = sol.asteroidCollision(asteroids);
    for (int i : res) {
        cout << i << " "; // 10
    }
    cout << "\n";

    asteroids = {8,-8};
    res = sol.asteroidCollision(asteroids);
    for (int i : res) {
        cout << i << " ";
    }
    cout << "\n";

    asteroids = {5,-15};
    res = sol.asteroidCollision(asteroids);
    for (int i : res) {
        cout << i << " "; // -15
    }
    cout << "\n";

    asteroids = {5,-15,10};
    res = sol.asteroidCollision(asteroids);
    for (int i : res) {
        cout << i << " "; // -15,10
    }
    cout << "\n";

    asteroids = {1,-1,-2,-2};
    res = sol.asteroidCollision(asteroids);
    for (int i : res) {
        cout << i << " "; // -2, -2
    }
    cout << "\n";
    return 0;
}

