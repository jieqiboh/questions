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

class MedianFinder {
public:
    priority_queue<double> maxh; // contains smallest elems, largest at top
    priority_queue<double, vector<double>, greater<double>> minh; // contains largest elems, smallest at top
    MedianFinder() {
    }

    void addNum(int num) {
        if (maxh.empty() || num <= maxh.top()) {
            maxh.push(num);
        } else {
            minh.push(num);
        }
        // rebalance heaps if needed
        if (maxh.size() > minh.size() + 1) {
            minh.push(maxh.top());
            maxh.pop();
        } else if (minh.size() > maxh.size()) {
            maxh.push(minh.top());
            minh.pop();
        }
    }

    double findMedian() {
        int size = minh.size() + maxh.size();
        if (size % 2 == 0) {
            return (maxh.top() + minh.top()) / (double)2;
        } else {
            return maxh.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
    fast();

    return 0;
}

