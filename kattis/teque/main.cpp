#include <deque>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <bitset>
#include <utility>

using namespace std;

void push_back(int x) {

}

void push_front(int x) {

}

void push_middle(int x) {

}

int get(int idx) {
    return 0;
}

int main() {
    // Your code goes here
    // Use t1 for elems in [0, (size+1)/2 - 1]
    // Use t2 for elems in [(size+1)/2, last]
    int n; cin >> n;

    deque<int> t1;
    deque<int> t2;

    while (n--) {
        string op; cin >> op;
        int num; cin >> num;

        cout << op << " " << num << endl;

    }
    return 0;
}

