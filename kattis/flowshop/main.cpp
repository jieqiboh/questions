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

template <typename T> void printVec(vector<T> s) {
    for (T x : s) {
        cout << x << " ";
    }
    cout << endl;
}

template <typename T> void printVecVec(vector<vector<T>> s) {
    for (vector<T> x : s) {
        printVec(x);
    }
    cout << endl;
}


int main() {
    // Sort of like a dp qn of sorts, where you can guarantee that order is from top down
    // since the 1st swathe always goes first, followed by 2nd etc...

    // Read in the inputs
    
    vector<vector<int>> arr;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        vector<int> s;
        for (int i=0; i < m; i++) {
            int stage_time;
            cin >> stage_time;
            s.push_back(stage_time);
        }
        arr.push_back(s);
    }

    //    printVecVec(arr);

    // get result, each idx corrs to swathe
    vector<int> res(n);
    int cur = 0;
    for (int i = 0; i < n; i++) { // init the first column
        res[i] = arr[i][0] + cur;
        cur += arr[i][0];
    }
    // printVec(res);

    for (int j = 1; j < m; j++) {
        vector<int> tmp(n);
        int cur = 0;
        for (int i = 0; i < n; i++) {
            tmp[i] = max(res[i], cur) + arr[i][j];
            cur = tmp[i];
        }
        // printVec(tmp);
        res = tmp;
    }

    printVec(res);


    return 0;
}
