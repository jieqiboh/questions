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
    // Your code goes here
    int n, m;
    while (cin >> n && cin >> m && !(n ==0 || m == 0)) {
        int total = n + m;
         unordered_set<int> s;
        //
         int count = 0;
        while (total--) {
            int cd; cin >> cd;
            if (s.find(cd) == s.end()) {
                s.insert(cd);
            } else {
                count++;
            }
        }
        cout << count << endl;;

    }
    return 0;
}

