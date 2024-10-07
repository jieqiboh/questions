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

class CustomStack {
    vector<int> v;
    int cap;
public:
    CustomStack(int maxSize): cap(maxSize) {}

    void push(int x) {
        if (v.size() == cap) return;
        v.push_back(x);
    }

    int pop() {
        if (v.empty()) return -1;
        int res = v[v.size() - 1];
        v.pop_back();
        return res;
    }

    void increment(int k, int val) {
        int vSize = v.size();
        for (int i = 0; i < k && i < vSize; i++) {
            v[i] += val;
        }
    }
    void print() {
        for (int i : v) {
            cout << i << " ";
        }
        cout << "\n";
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

int main() {
    fast();

    CustomStack* obj = new CustomStack(5);
    obj->push(2);
    cout << obj->pop() << "\n";
    obj->increment(3,1);
    obj->push(5);
    obj->push(6);
    obj->print();
    obj->increment(2,1);
    obj->print();

    return 0;
}

