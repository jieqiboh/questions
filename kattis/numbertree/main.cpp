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
    int height; cin >> height;
    string path; cin >> path;

    //    cout << path << endl;

    int size = 1;

    for (int i=0;i<=height;i++) {
        size*=2;
    }
    size--;
    
    //compute
    int left = 1;
    int right = 2;
    int tmp;
    for (char c : path) {
        if (c == 'L') {
            size -= left;
            tmp = left;
            left = tmp * 2;
            right = tmp * 2 + 1;
        } else if (c == 'R') {
            size -= right;
            tmp = right;
            left = tmp * 2 - 1;
            right = tmp * 2;
        }
        // cout << "left: " << left << endl;
        // cout << "right: " << right << endl;
    }
    cout << size;
    return 0;
}

