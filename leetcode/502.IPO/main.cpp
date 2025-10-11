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

struct CapitalCompare {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
        return a.first > b.first;
        // return true if 'a' should come after 'b'
    }
};

struct ProfitCompare {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
        return a.second < b.second; // greatest profit should be at the front
    }
};

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, CapitalCompare> pqcap;
        priority_queue<pair<int,int>, vector<pair<int,int>>, ProfitCompare> pqprofit;

        for (int i = 0; i < capital.size(); i++) {
            pair<int,int> p = {capital[i], profits[i]};
            pqcap.push(p);
        }

        for (int i = 0; i < k; i++) {
            // first move all the doable projects to pqprofit
            while (!pqcap.empty() && w >= pqcap.top().first) {
                pair<int,int> cur = pqcap.top();
                pqprofit.push(cur);
                pqcap.pop();
            }

            // then grab the most profitable from pqprofits
            if (pqprofit.empty()) continue;
            w += pqprofit.top().second; // add the profit
            pqprofit.pop();
        }

        return w;
    }
};

int main() {
    fast();
    Solution sol;
    int k = 3;
    int w = 0;
    vector<int> profits = {1,2,3};
    vector<int> capital = {0,1,2};
    cout << sol.findMaximizedCapital(k, w, profits, capital) << "\n";

    return 0;
}

