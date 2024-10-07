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

class MyCalendar {
    set<pair<int, int>> cal;
public:
    bool book(int start, int end) {
        if (cal.empty()) {
            cal.insert({start, end});
            return true;
        }
        // Finding nextEvent where nxtEvent.start >= start
        auto it = cal.lower_bound({start, end});
        if ((it != cal.end() && end > it->first)) { // next event is not end of list
            return false;
        }
        if (it != cal.begin() && start < prev(it)->second) return false;
        cal.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

int main() {
    fast();
    MyCalendar* obj = new MyCalendar();
    cout << obj->book(10,30) << "\n"; // 1
    cout << obj->book(10,30) << "\n"; // 0
    cout << obj->book(1,2) << "\n";   // 1
    cout << obj->book(30,35) << "\n"; // 1
    cout << obj->book(8,10) << "\n"; // 1
    cout << obj->book(8,11) << "\n"; // 0

    cout << "\n";
    free(obj);

    obj = new MyCalendar();
    cout << obj->book(10,20) << "\n"; // 1
    cout << obj->book(15,25) << "\n"; // 0
    cout << obj->book(20,30) << "\n";   // 1

    return 0;
}

