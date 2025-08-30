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
#define ll long long

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

class NumberContainers {
public:
    unordered_map<int,int> idx_num; // maps idx to numbers
    unordered_map<int,set<int>> num_set; // maps numbers to a ordered set of their idxes
    NumberContainers() {}

    void change(int index, int number) {
        // update idx_num
        int prevNum = -1;
        if (idx_num.find(index) != idx_num.end()) {
            prevNum = idx_num[index];
        }
        idx_num[index] = number;

        if (prevNum != -1) {
            num_set[prevNum].erase(index);
            if (num_set[prevNum].empty()) { // erase the set altogether if it becomes empty
                num_set.erase(prevNum);
            }
        }
        num_set[number].insert(index);
    }

    int find(int number) {
        if (num_set.find(number) == num_set.end()) return -1;
        return *num_set[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */

int main() {
    fast();
    NumberContainers* obj = new NumberContainers();
    int index = 5;
    int number = 10;
    obj->change(index,number);
    int param_2 = obj->find(number);
    cout << param_2 << "\n"; // 5

    return 0;
}

