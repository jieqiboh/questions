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

int main() {
    // Your code goes here
    int n; cin >> n;

    while (n--) {
        int num; cin >> num;

        vector<int> v;


        for (int i = 0; i < 20;i++) {
            int x; cin >> x;
            v.push_back(x);
        }

        // perform insertion sort on array
        int steps = 0;

        for (int i=1; i < v.size(); i++) {
            while ((v[i] < v[i-1]) && (i > 0)) {
                int tmp = v[i];
                v[i] = v[i - 1];
                v[i - 1] = tmp;
                steps++;
                i--;
            }
        }
        cout << num << " " << steps << endl;
    }

    return 0;
}

