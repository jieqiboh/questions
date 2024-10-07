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

class StockSpanner {
    stack<pair<int,int>> s;
public:
    StockSpanner() {
    }

    int next(int price) {
        if (s.empty()) {
            s.push({price, 1});
            return 1;
        } else {
            int count = 1;
            while (!s.empty() && s.top().first <= price) {
                count+=s.top().second;
                s.pop();
            }
            s.push({price, count});
            return count;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main() {
    fast();

    return 0;
}

