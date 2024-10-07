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

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class TimeMap {
public:
    unordered_map<string, vector<pair<string,int>>> store; // key value timestamp
    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        store[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp) {
        if (store.find(key) == store.end()) return "";
        return binSearch(timestamp, store[key]);
    }

    string binSearch(int target, vector<pair<string, int>>& values) {
        // returns the idx of the pair where pair.second is the highest val <= target
        int l = 0;
        int r = values.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (values[mid].second == target) {
                return values[mid].first;
            } else if (values[mid].second < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return (l == 0) ? "" : values[l - 1].first;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main() {
    fast();
    TimeMap *timeMap = new TimeMap();
    timeMap->set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
    cout << timeMap->get("foo", 1) << "\n";         // return "bar"
    cout << timeMap->get("foo", 3) << "\n";         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
    timeMap->set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
    cout << timeMap->get("foo", 4) << "\n";         // return "bar2"
    cout << timeMap->get("foo", 5) << "\n";         // return "bar2"
    free(timeMap);

    timeMap = new TimeMap();
    timeMap->set("foo", "high", 10);
    timeMap->set("foo", "low", 20);
    cout << timeMap->get("foo", 5) << "\n"; // ""
    cout << timeMap->get("foo", 15) << "\n";// high
    cout << timeMap->get("foo", 20) << "\n";// low
    cout << timeMap->get("foo", 25) << "\n";// low

    return 0;
}

