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
class MyCircularDeque {
    vector<int> nums;
    int f;
    int b;
    int cap;
    int cnt; // current no of elements
public:
    MyCircularDeque(int k) {
        nums = vector<int>(k);
        cnt = 0;
        cap = k;
        f = 0;
        b = k - 1;
    }
    // f and b point to the latest inserted elem in the deque. initially they are at opposite ends
    // f moves +ve
    // b moves -ve

    bool insertFront(int value) {
        if (isFull()) return false;
        f = (f - 1 + cap) % cap;
        nums[f] = value;
        cnt++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        b = (b + 1) % cap;
        nums[b] = value;
        cnt++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        f = (f + 1) % cap;
        cnt--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        b = (b - 1 + cap) % cap;
        cnt--;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return nums[f];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return nums[b];
    }

    bool isEmpty() {
        return cnt == 0;
    }

    bool isFull() {
        return cnt == cap;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

int main() {
    fast();

    return 0;
}

