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

    string s;

    while (getline(cin, s)) {
        bool valid = true;
        istringstream iss(s);

        vector<int> nums;
        int n;
        while (iss >> n) nums.push_back(n);
//        for (int x : nums) {
//            cout << x << " ";
//        }
//        cout << endl;
        set<int> unique_diffs;
        for (int i=0;i<nums.size();i++) {
            if (!valid) break;

            for (int j=i+1;j<nums.size();j++) {
                int diff = abs(nums[i] - nums[j]);
                if (unique_diffs.find(diff) != unique_diffs.end()) {
                    valid = false; break;
                } else {
                    unique_diffs.insert(diff);
                }
            }
        }

        sort(nums.begin(), nums.end());

        if (!valid) {
            cout << "not a ruler" << endl;
        } else {
//            cout << "nb " << nums.back();
            if (unique_diffs.size() == nums.back()) {// if perfect
                cout << "perfect" << endl;
            } else {
                cout << "missing";
                for (int i = 1; i < nums.back();i++) {
                    if (unique_diffs.find(i) == unique_diffs.end()) cout << " " << i;
                }
                cout << endl;
            }
        }
    }

    return 0;
}

