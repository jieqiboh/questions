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
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        unordered_set<char> ops = {'-', '+', '*'};
        for (int i = 0; i < expression.size(); i++) {
            vector<int> left, right;
            if (ops.find(expression[i]) != ops.end()) {
                left = diffWaysToCompute(expression.substr(0, i));
                right = diffWaysToCompute(expression.substr(i + 1));
            }
            if (expression[i] == '*') {
                for (int i = 0; i < left.size(); i++) {
                    for (int j = 0; j < right.size(); j++) {
                        res.push_back(left[i] * right[j]);
                    }
                }
            } else if (expression[i] == '-') {
                for (int i = 0; i < left.size(); i++) {
                    for (int j = 0; j < right.size(); j++) {
                        res.push_back(left[i] - right[j]);
                    }
                }
            } else if (expression[i] == '+')
                for (int i = 0; i < left.size(); i++) {
                    for (int j = 0; j < right.size(); j++) {
                        res.push_back(left[i] + right[j]);
                    }
                }
        }
        if (res.empty()) {
            res.push_back(stoi(expression));
        }
        return res;
    }
};

int main() {
    fast();
    Solution sol;
    string expression = "2-1-1";
    vector<int> res = sol.diffWaysToCompute(expression);
    for (int i : res) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}

