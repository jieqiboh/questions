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

int main() {
    fast();

    unordered_map<char, int> maxMap; // maps chars to their max

    char curChar = 'x';
    int curCount = 0;
    string input; cin >> input;
    for (int i = 0; i < input.size(); i++) {
        char c = input[i];
        if (c != curChar) {
            maxMap[curChar] = max(maxMap[curChar], curCount);
            curChar = c;
            curCount = 1;
        } else {
            curCount++;
        }
    }
    maxMap[curChar] = max(maxMap[curChar], curCount);

    int maxVal = 0;
    for (pair<char, int> p : maxMap) {
//        cout << p.first << " " << p.second << "\n";
        maxVal = max(p.second, maxVal);
    }
    cout << maxVal;
    return 0;
}

