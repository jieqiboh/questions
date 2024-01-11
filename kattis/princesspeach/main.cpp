#include <iostream>
#include <unordered_set>
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

int main() {
    int total, cur; cin >> total >> cur;

    // fast lookup if an elem is inside, and fast insertioon
    unordered_set<int> found;

    // cout << total << endl;
    // cout << cur << endl;

    for (int i=0;i<cur;i++) {
        int x; cin >> x;
        found.insert(x);
    }
    
    int actual_found = 0;
    for (int i=0;i<total;i++) {
        if (found.find(i) == found.end()){
            cout << i << endl;
        } else {
            actual_found++;
        }
    }
    cout << "Mario got " << actual_found << " of the dangerous obstacles." << endl;
    
    return 0;
}

