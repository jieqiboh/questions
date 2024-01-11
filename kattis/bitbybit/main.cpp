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

void printVec(vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        char x = (v[i] == -1) ? '?' : (v[i] + '0');
        cout << x;
    }
    cout << endl;
}

int main() {
    // Your code goes here
    int n; cin >> n; cin.ignore();

    while (n != 0) {
        vector<int> arr(32, -1);
        for (int i = 0; i < n;i++) {
            string op;
            cin >> op;

            if (op == "SET") {
                int idx; cin >> idx;
                arr[idx] = 1;
            } else if (op == "CLEAR") {
                int idx; cin >> idx;
                arr[idx] = 0;
            } else if (op == "OR") {
                int src, dst; cin >> dst >> src;
                if(arr[src] == 1 || arr[dst] == 1) {
                    arr[dst] = 1;
                }
                else if (arr[src] == 0 && arr[dst] == 0) {
                    arr[dst] = 0;
                }
                else {
                    arr[dst] = -1;
                }
            } else if (op == "AND") {
                int src, dst; cin >> dst >> src;
                if(arr[dst] == 1 && arr[src] == 1) {
                    arr[dst] = 1;
                }
                else if(arr[dst] == 0 || arr[src] == 0) {
                    arr[dst] = 0;
                }
                else {
                    arr[dst] = -1;
                }
            }

        }
        // reverse the array
        reverse(arr.begin(), arr.end());
        printVec(arr);
        cin >> n; cin.ignore();
    }
    return 0;
}

