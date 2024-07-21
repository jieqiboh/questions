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

#define uset unordered_set
#define umap unordered_map
#define endl '\n'

typedef vector<int> vi;
typedef long long ll;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class MinStack {
public:
    stack<int> s;
    vector<int> min;

    MinStack() = default;
    
    void push(int val) {
        s.push(val);
        if (min.size() == 0 || val < min[min.size() - 1]) { // new min found
            min.push_back(val);
        } else {
            min.push_back(min[min.size() - 1]);
        }
    }
    
    void pop() {
        s.pop();
        min.pop_back();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        int min_tmp = min[min.size() - 1];
        return min_tmp;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    fast();

    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << "\n"; // return -3
    minStack.pop();
    cout << minStack.top() << "\n";    // return 0
    cout << minStack.getMin() << "\n"; // return -2

    MinStack minStack2;
    minStack2.push(-2);
    minStack2.push(0);
    minStack2.push(-3);
    cout << minStack2.getMin() << "\n"; // return -3
    minStack2.pop();
    cout << minStack2.top() << "\n";    // return 0
    cout << minStack2.getMin() << "\n"; // return -2

    return 0;
}

