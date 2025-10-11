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

int subordinates(int i, unordered_map<int, vector<int>>& adjList, unordered_map<int,int>& memo) {
    if (adjList[i].empty()) return 0;
    if (memo.find(i) != memo.end()) return memo[i];

    int result = 0;
    for (int y : adjList[i]) {
        result += 1;
        result += subordinates(y, adjList, memo);
    }

    memo[i] = result;
    return result;
}

int main() {
    fast();

    int n; cin >> n;
    vector<int> employees(n);

    unordered_map<int,vector<int>> adjList(n); // maps each employee number to their direct subordinates

    for (int i = 1; i < n; i++) {
        int x; cin >> x;
        employees[i] = x;
        adjList[x].push_back(i+1);
    }

//    for (pair<int, vector<int>> p : adjList) {
//        cout << p.first << ": ";
//        for (int x : p.second) {
//            cout << x << " ";
//        }
//        cout << "\n";
//    }

    unordered_map<int,int> memo;
    for (int i = 0; i < n; i++) {
        cout << subordinates(i+1, adjList, memo) << " ";
    }

    return 0;
}

