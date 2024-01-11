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

#define uset unordered_set
#define umap unordered_map
#define endl '\n'

typedef vector<int> vi;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

template <typename T> void printVec(vector<T> s) {
    for (T x : s) {
        cout << x;
    }
    cout << endl;
}

int main() {
    fast();
    int max = 0;
    int best = 0;
    for (int i = 1; i <= 5; i++) {
        int sum = 0;
        for (int j=0;j<4;j++){
            int score;
            cin >> score;
            sum += score;
        }
        if (sum > max){
            max = sum;
            best = i;
        }
    }
    cout << best << " " << max;

    return 0;
}

