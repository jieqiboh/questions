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
#include <bits/stdc++.h>

using namespace std;

#define uset unordered_set
#define umap unordered_map
#define endl '\n'

typedef vector<int> vi;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int dist(string& a, string& b) { // computes distance between 2 strings a and b
    int count = 0;
    uset<char> mySet(b.begin(), b.end());
    // find number of same elements between the 2 strings

    for (char c : a) {
        if (mySet.find(c) != mySet.end()) {
            count++;
        }
    }
    return count;
}

int main() {
    fast();

    int num_r; cin >> num_r;

    vector<string> routines(num_r);
    for (auto& i : routines) {
        cin >> i;
    }
//    for (string s : routines) {
//        cout <<  s << endl;
//    }
    vector<int> v_idx(num_r); // array representing idxes in routines
    for (int i=0;i<v_idx.size();i++) {
        v_idx[i] = i;
    }

    // then create a distance table mapping distance[i][j] to the distance between 2 routines strings with idx i and j
    vector<vector<int>> distance(num_r, vector<int>(num_r));
    for (int i = 0; i < distance.size(); i++) {
        for (int j = 0; j < distance.size(); j++) {
            distance[i][j] = dist(routines[i], routines[j]);
        }
    }

//    for (auto& x : distance) {
//        for (auto& y : x) {
//            cout << y << " ";
//        }
//        cout << endl;
//    }


    int min = INT8_MAX;
    do {
        // for each permutation, compute the number of quick changes
        int count = 0;

        for (int i = 0; i < v_idx.size()-1; i++) {
            int first_idx = v_idx[i];
            int second_idx = v_idx[i+1];
            count += distance[first_idx][second_idx]; // get the distance between adj routines
        }
        if (count < min) {
            min = count;
        }
    } while (next_permutation(v_idx.begin(), v_idx.end()));

    cout << min;

    return 0;
}

