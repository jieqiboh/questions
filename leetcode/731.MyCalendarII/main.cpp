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

class MyCalendarTwo {
    set<pair<int,int>> cal;
    vector<pair<int,int>> dblOverlaps;
public:
    MyCalendarTwo() {
    }

    bool book(int start, int end) {
        pair<int,int> event = make_pair(start, end);

        for (pair<int,int> p : dblOverlaps) {
            if (isOverlap(p, event)) return false;
        }
        for (pair<int,int> p : cal) {
            if (isOverlap(p, event)) {
                dblOverlaps.push_back(make_pair(max(p.first, event.first), min(p.second, event.second)));
            }
        }
        cal.insert(event);
        return true;
    }
    bool isOverlap(pair<int,int> a, pair<int,int> b) {
        return max(a.first, b.first) < min(a.second, b.second);
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */

int main() {
    fast();
    MyCalendarTwo sol;
    cout << sol.book(10,20) << "\n"; // 1
    cout << sol.book(50,60) << "\n"; // 1
    cout << sol.book(10,40) << "\n"; // 1
    cout << sol.book(5,15) << "\n";  // 0
    cout << sol.book(5,10) << "\n";  // 1
    cout << sol.book(25,55) << "\n";  // 1

    return 0;
}

