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


void goUp(vector<vector<char>>&, int&, int&, int&, int&);
void goDown(vector<vector<char>>&, int&, int&, int&, int&);
void goLeft(vector<vector<char>>&, int&, int&, int&, int&);
void goRight(vector<vector<char>>&, int&, int&, int&, int&);

template <typename T> void printVec(vector<T> s) {
    for (T x : s) {
        cout << x;
    }
    cout << endl;
}

template <typename T> void printVecVec(vector<vector<T>> s) {
    for (vector<T> x : s) {
        printVec(x);
    }
}

void findStart(vector<vector<char>>& arr, int& starti, int& startj) {
    for (int i=0;i<arr.size();i++){
        vector<char> row = arr[i];
        for (int j=0;j<row.size();j++){
            if (arr[i][j] == '*') {
                starti = i;
                startj = j;
            }
        }
    }
}


void goRight(vector<vector<char>>& arr, int& starti, int& startj, int& endi, int& endj) {
    for (int j=startj+1;j<arr[starti].size();j++) {
        char c = arr[starti][j];
        startj = j;

        if (c == 'x') {
            endi = starti; endj = j;
            break;
        } else if (c == '\\') {
            goDown(arr, starti, startj, endi, endj);
            break;
        } else if (c == '/') {
            goUp(arr, starti, startj, endi, endj);
            break;
        }
//        else {
//            arr[starti][j] = 'y';
//        }
    }
}

void goLeft(vector<vector<char>>& arr, int& starti, int& startj, int& endi, int& endj) {
    for (int j=startj-1;j>=0;j--) {
        char c = arr[starti][j];
        startj = j;

        if (c == 'x') {
            endi = starti; endj = j;
            break;
        } else if (c == '\\') {
            goUp(arr, starti, startj, endi, endj);
            break;
        } else if (c == '/') {
            goDown(arr, starti, startj, endi, endj);
            break;
        }
//        else {
//            arr[starti][j] = 'y';
//        }
    }
}


void goDown(vector<vector<char>>& arr, int& starti, int& startj, int& endi, int& endj) {
    for (int i=starti+1;i<arr.size();i++) {
        char c = arr[i][startj];
        starti = i;

        if (c == 'x') {
            endi = i; endj = startj;
            break;
        } else if (c == '\\') {
            goRight(arr, starti, startj, endi, endj);
            break;
        } else if (c == '/') {
            goLeft(arr, starti, startj, endi, endj);
            break;
        }
//        else {
//            arr[i][startj] = 'y';
//        }
    }
}


void goUp(vector<vector<char>>& arr, int& starti, int& startj, int& endi, int& endj) {
    for (int i=starti-1;i>=0;i--) {
        char c = arr[i][startj];
        starti = i;

        if (c == 'x') {
            endi = i; endj = startj;
            break;
        } else if (c == '\\') {
            goLeft(arr, starti, startj, endi, endj);
            break;
        } else if (c == '/') {
            goRight(arr, starti, startj, endi, endj);
            break;
        }
//        else {
//            arr[i][startj] = 'y';
//        }
    }
}

int main() {
    // Your code goes here
    int w, l; cin >> w >> l;
    int count = 1;
    while (w != 0 && l != 0) {
        cout << "HOUSE " << count << endl;
        count++;

//        cout << w << " " << l << endl;
        vector<vector<char>> arr(l, vector<char>(w));

        int starti, startj, endi, endj;

        for (vector<char>& v : arr) {
            for (auto& x : v) {
                cin >> x;
            }
        }


        // process arr
        // starti is the row, startj is the col
        findStart(arr, starti, startj);
//        cout << "startrow: " << starti << " startcol: " << startj << endl;

        if (startj == 0) { // start from left
            goRight(arr, starti, startj, endi, endj);
        } else if (starti == 0) { // start from top
            goDown(arr, starti, startj, endi, endj);
        } else if (startj == w-1) { //start from right
            goLeft(arr, starti, startj, endi, endj);
        } else if (starti == l-1) { // start from bottom
            goUp(arr, starti, startj, endi, endj);
        }
        arr[endi][endj] = '&';

//        cout << "endrow: " << endi << " endcol: " << endj << endl;

        printVecVec(arr);
        // do cin again
        cin >> w >> l;
    }
    return 0;
}
