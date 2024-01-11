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


void printVec(vector<int> seq);

int main() {
    // Your code goes here
    vector<int> seq;
    int n; cin >> n;

    int min = 0;

    for (int i=0;i<n;i++) {
        int j; cin >> j;
        if (j > min) {
            min = j;
            seq.push_back(j);
        }
    }
    printVec(seq);
    return 0;
}

void printVec(vector<int> seq) {
    cout << seq.size() << endl;
    for (int x : seq) {
        cout << x << " ";
    }
    cout << endl;
}

