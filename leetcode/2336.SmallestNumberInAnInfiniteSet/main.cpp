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

class SmallestInfiniteSet {
public:
    set<int> s;
    SmallestInfiniteSet() {
        for (int i = 1; i < 1000; i++) {
            s.emplace(i);
        }
    }

    int popSmallest() {
        const int res = *s.begin();
        s.erase(s.begin());
        return res;
    }

    void addBack(int num) {
        s.emplace(num);
    }
};


/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

int main() {
    fast();

    return 0;
}

