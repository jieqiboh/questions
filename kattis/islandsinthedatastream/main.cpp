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
    int n; cin >> n; cin.ignore();

    for(int i = 0; i < n; i++) {
        string s; getline(cin, s);

        vector<int> ints;
        istringstream iss(s);
        int nbr;
        while (iss >> nbr) {
            ints.push_back(nbr);
        }
        ints.erase(ints.begin());
        // for (int c : ints) {
        //     cout << c << " ";
        //     
        // }
        // cout << endl;
        
        stack<int> stk;
        int count = 0;
        for (int x : ints) { // ignore the first int
//            cout << "Looking at " << x;
            if (stk.empty() || x > stk.top()) {
//                cout << " pushed";
                stk.push(x);
            } else {
                while (!stk.empty() && stk.top() > x) {
//                    cout << " count++ ";
                    count++;
                    stk.pop();
                }
                if (stk.empty() || x > stk.top()) { // have to check if need to push onto stack
//                    cout << " pushed";
                    stk.push(x);
                }
            }
//            cout << endl;
        }
        cout << i+1 << " " << count << endl;
    }
    return 0;
}

